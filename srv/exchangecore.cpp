#include "exchangecore.hpp"


#include <stdexcept>

#include <iostream>

namespace gramia {

TradeSessionTimeStamp GetCurrentTimeStamp()
{
    TradeSessionTimeStamp result = 0;

    return result;
}


ExchangeCore::ExchangeCore()
    : m_TradeSessionStarted(GetCurrentTimeStamp())
{
}

ExchangeCore::~ExchangeCore()
{

}

BuyResult ExchangeCore::Buy(
        Trader::ID buyer,
        bool anonymous,
        stock resource,
        StockPrice price,
        StockPrice value)
{

    OrderResult orr = GetOrderList(resource).PullOutOrders(price, value);

    std::cout << "ExchangeCore::Buy 2" << std::endl;

    BuyResult result(orr.Orders, buyer, anonymous, GetTimeStamp());

    std::cout << "ExchangeCore::Buy 3" << std::endl;

    if (!orr.Completed)
    {
        Order o(
                    GetOther(resource),
                    m_IdGenerator.GetNew(),
                    orr.RemainValue,
                    price.GetInverted(),
                    GetTimeStamp(),
                    buyer,
                    anonymous);

        std::cout << "ExchangeCore::Buy 4" << std::endl;

        GetOrderList(GetOther(resource)).AddOrder(o);
        result.CreatedOrder = o.Id;

        std::cout << "ExchangeCore::Buy 5" << std::endl;
    }

    std::cout << "ExchangeCore::Buy 6" << std::endl;


    return result;
}

const OrderList& ExchangeCore::GetOrderList(stock st) const
{
    if (st == st1) return m_Orders_st1;
    if (st == st2) return m_Orders_st2;

    throw std::invalid_argument("Invalid resource");
}

OrderList& ExchangeCore::GetOrderList(stock st)
{
    if (st == st1) return m_Orders_st1;
    if (st == st2) return m_Orders_st2;

    throw std::invalid_argument("Invalid resource");
}

OrderArray ExchangeCore::Dump(stock resource, unsigned count) const
{
    return GetOrderList(resource).Dump(count);
}

OrderArray ExchangeCore::Dump(unsigned count) const
{
    OrderArray result = GetOrderList(st1).Dump(count);

    OrderArray r2 = GetOrderList(st2).Dump(count);

    result.insert(result.end(), r2.begin(), r2.end());

    return result;
}



TradeSessionTimeStamp ExchangeCore::GetTimeStamp() const
{
    return (GetCurrentTimeStamp() - m_TradeSessionStarted);
}

}
