#include "order.hpp"

namespace gramia
{

Order::Order(
        stock resource,
        ID id,
        StockPrice price,
        StockVolume volume,
        TradeSessionTimeStamp created,
        Trader::ID creator,
        bool anonymous,
        TradeSessionTimeStamp expire)
    : Resourse(resource),
      Id(id),
      Price(price),
      Volume(volume),
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
