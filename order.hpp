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
    typedef unsigned ID;

    Order(
        stock resource,
        ID id,
        StockPrice price = 0.0,
        StockVolume volume = 0.0,
        TradeSessionTimeStamp created = 0,
        Trader::ID creator = 0,
        bool anonymous = true,
        TradeSessionTimeStamp expire = 0);
    virtual ~Order() {}

    ID Id;
    stock Resourse;
    StockVolume Volume;
    TradeSessionTimeStamp Created;
    Trader::ID Creator;
    StockPrice Price;

    TradeSessionTimeStamp Expire;
    bool Anonymous;

    Order Cut(StockVolume volume);
    static Order GetEmpty();

    bool empty() const noexcept
    {        
        return (bool)m_ID;
    }    
protected:  
    
};

}

#endif // ORDER_HPP
