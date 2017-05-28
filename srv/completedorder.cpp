#include "completedorder.hpp"

namespace gramia {

CompletedOrder::CompletedOrder(
        const Order &source,
        Trader::ID buyer,
        bool anonymous,
        TradeSessionTimeStamp timestamp)
    :  Order(source),
      Buyer(buyer),
      BuyerAnonymous(anonymous),
      Completed(timestamp)
{

}

CompletedOrder::~CompletedOrder()
{
}

}
