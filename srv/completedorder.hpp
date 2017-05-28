#ifndef COMPLETEDORDER_HPP
#define COMPLETEDORDER_HPP

#include "order.hpp"

namespace gramia
{

class CompletedOrder
        : public Order
{
public:
    CompletedOrder(
            const Order& source,
            Trader::ID buyer = 0,
            bool anonymous = true,
            TradeSessionTimeStamp timestamp = 0);
    virtual ~CompletedOrder();

    Trader::ID Buyer;
    bool BuyerAnonymous;
    TradeSessionTimeStamp Completed;
};

}

#endif // COMPLETEDORDER_HPP
