#ifndef EXCHANGECORE_HPP
#define EXCHANGECORE_HPP

#include "orderlist.hpp"
#include "completedorder.hpp"

namespace gramia
{

typedef BaseOrderArray<CompletedOrder> CompletedOrderArray;

class BuyResult
{
public:
    BuyResult() {}
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
};

}

#endif // EXCHANGECORE_HPP
