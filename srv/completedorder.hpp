#ifndef COMPLETEDORDER_HPP
#define COMPLETEDORDER_HPP

#include "order.hpp"

namespace gramia
{

class CompletedOrder
        : public Order
{
public:
    CompletedOrder();
    virtual ~CompletedOrder();

    Trader::ID Buyer;
    bool BuyerAnonymous;
    TradeSessionTimeStamp Completed;
};

}

#endif // COMPLETEDORDER_HPP
