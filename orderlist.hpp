#ifndef ORDERLIST_HPP
#define ORDERLIST_HPP

#include "order.hpp"

#include <list>
#include <vector>

namespace gramia
{

typedef std::vector<Order> OrderArray;

class OrderList
{
public:
    OrderList();
    ~OrderList();    

    void AddOrder(const Order& o);

    bool IsExist(Order::ID id) const noexcept;
    Order CancelOrder(Order::ID id);
    OrderArray CancelOrdersByCreator(Trader::ID tr);
    OrderArray PullOutOrders(StockPrice value);

    OrderArray Dump(StockPrice from, StockPrice to) const;
    double TotalVolume(StockPrice target) const;
    double CalcCost(StockPrice target) const;
protected:
    typedef std::list<Order> OrderContainer;
    OrderContainer m_Container;

    OrderContainer::const_iterator FindOrder(Order::ID id) const;
};

}

#endif // ORDERLIST_HPP
