#include "order.hpp"

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


}
