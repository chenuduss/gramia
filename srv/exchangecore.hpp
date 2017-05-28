#ifndef EXCHANGECORE_HPP
#define EXCHANGECORE_HPP

#include "orderlist.hpp"
#include "completedorderarray.hpp"
#include "idgenerator.hpp"

namespace gramia
{



class BuyResult
{
public:
    BuyResult(
            const BaseOrderArray<Order>& sourceOrders = BaseOrderArray<Order>(),
            Trader::ID buyer = 0,
            bool anonymous = true,
            TradeSessionTimeStamp timestamp = 0)
        : CreatedOrder(0),
          Orders(sourceOrders, buyer, anonymous, timestamp)
    {

    }

    ~BuyResult() {}

    CompletedOrderArray Orders;
    Order::ID CreatedOrder;
};

class ExchangeCore
{
public:
    ExchangeCore();
    ~ExchangeCore();

    BuyResult Buy(
            Trader::ID buyer,
            bool anonymous,
            stock resource,
            StockPrice price,
            StockPrice value);

    OrderCancelResult CancelOrder(Trader::ID requestor, Order::ID order);

    OrderArray Dump(unsigned count) const;
    OrderArray Dump(stock resource, unsigned count) const;
protected:

    OrderList m_Orders_st1;
    OrderList m_Orders_st2;

    OrderList& GetOrderList(stock st);
    const OrderList& GetOrderList(stock st) const;

    TradeSessionTimeStamp m_TradeSessionStarted;
    TradeSessionTimeStamp GetTimeStamp() const;

    IdGenerator<unsigned long long> m_IdGenerator;
};

}

#endif // EXCHANGECORE_HPP
