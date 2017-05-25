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
    ~Order() {}

    operator bool() const noexcept
    {
        return (bool)m_ID;
    }

    ID GetID() const noexcept
    {
        return m_ID;
    }
    StockVolume GetVolume() const noexcept
    {
        return m_Volume;
    }

    const stock Resourse;
    const TradeSessionTimeStamp Created;
    const Trader::ID Creator;
    const StockPrice Price;


    TradeSessionTimeStamp Expire;
    bool Anonymous;

    Order Cut(StockVolume volume);

    static Order GetEmpty();
private:
    ID m_ID;
    StockVolume m_Volume;
};

}

#endif // ORDER_HPP
