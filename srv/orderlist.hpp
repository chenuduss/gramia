#ifndef ORDERLIST_HPP
#define ORDERLIST_HPP

#include "order.hpp"
#include "orderarray.hpp"

#include <list>
#include <vector>

namespace gramia
{

const StockPrice StockPriceMin(0.00001);
const StockPrice StockPriceMax(100000);

const StockVolume StockVolumeMin(0.00001);
const StockVolume StockVolumeMax(100000);

class OrderResult
{
public:
    OrderResult()
        : Completed(false)
    {

    }
    ~OrderResult() {}

    bool Completed;
    OrderArray Orders;
    StockPrice RemainValue;
};

class OrderList
{
public:
    OrderList();
    ~OrderList();    

    void AddOrder(const Order& o);

    bool IsExist(Order::ID id) const noexcept;
    Order CancelOrder(Order::ID id);
    OrderArray CancelOrdersByCreator(Trader::ID tr);

    OrderResult PullOutOrders(StockPrice price, StockPrice value);

    OrderArray Dump(StockPrice from, StockPrice to) const;
    StockPrice TotalVolume(StockPrice target) const;
    StockPrice TotalValue(StockPrice target) const;

    unsigned Count() const
    {
        m_Container.size();
    }

protected:
    typedef std::list<Order> OrderContainer;
    OrderContainer m_Container;

    OrderContainer::const_iterator FindOrder(Order::ID id) const;
};

}

#endif // ORDERLIST_HPP
