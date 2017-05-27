#include "order.hpp"

#include <stdexcept>

#include <iostream>

namespace gramia
{

Order::Order(
        stock resource,
        ID id,
        StockVolume volume,
        StockPrice price,        
        TradeSessionTimeStamp created,
        Trader::ID creator,
        bool anonymous,
        TradeSessionTimeStamp expire)
    : Resourse(resource),
      Id(id),
      Volume(volume),
      Price(price),      
      Created(created),
      Creator(creator),
      Anonymous(anonymous),
      Expire(expire)
{
}

Order Order::GetEmpty()
{
    return Order(stInvalid, 0);
}

FloatNumber Order::GetValue() const
{
    return FloatNumber(Price * Volume);
}

Order Order::Cut(StockVolume volume)
{
    Volume -= volume;

    return Order(Resourse, Id, volume, Price, Created, Creator, Anonymous, Expire);
}

}
