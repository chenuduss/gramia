#ifndef ORDERLIST_HPP
#define ORDERLIST_HPP

#include "order.hpp"

#include <list>
#include <vector>

namespace gramia
{

class OrderList
{
public:
    OrderList();
    ~OrderList();

    typedef std::vector<Order> OrderArray;

    void AddOrder(const Order& o);
    OrderArray PullOutOrders(StockPrice price);

    OrderArray Dump(StockPrice from, StockPrice to) const;
    double TotalVolume(StockPrice target) const;
protected:
    typedef std::list<Order> OrderContainer;
    OrderContainer m_Container;
};

}

#endif // ORDERLIST_HPP
