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
        StockVolume volume = 0.0,
        StockPrice price = 0.0,        
        TradeSessionTimeStamp created = 0,
        Trader::ID owner = 0,
        bool anonymous = true,
        TradeSessionTimeStamp expire = 0);
    virtual ~Order() {}
    
    stock Resourse;
    ID Id;
    StockVolume Volume;
    StockPrice Price;
    TradeSessionTimeStamp Created;
    Trader::ID Owner;
    bool Anonymous;
    TradeSessionTimeStamp Expire;    

    Order Cut(StockVolume volume);

    FloatNumber GetValue() const;
    static Order GetEmpty();

    bool empty() const noexcept
    {        
        return (Volume == 0.0);
    }    
protected:  
    
};

}

#endif // ORDER_HPP
