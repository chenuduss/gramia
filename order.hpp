#ifndef ORDER_HPP
#define ORDER_HPP

#include "stock.hpp"
#include "trader.hpp"
#include "TradeSessionTimeStamp.hpp"

namespace gramia
{

class Order
{
public:
    Order(
        stock source,
        StockPrice price = 0.0,
        double volume = 0.0,
        TradeSessionTimeStamp created = 0,
        Trader::ID creator = 0,
        TradeSessionTimeStamp expire = 0);
    ~Order() {}

    stock Source;
    StockPrice Price;
    double Volume;    
    TradeSessionTimeStamp Created;
    Trader::ID Creator;
    TradeSessionTimeStamp Expire;
};

}

#endif // ORDER_HPP
