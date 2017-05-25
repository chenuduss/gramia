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
      m_ID(id),
      Price(price),
      m_Volume(volume),
      Created(created),
      Creator(creator),
      Anonymous(anonymous),
      Expire(expire)
{
}

Order Order::GetEmpty()
{
    return Order(st1, 0);
}


}
