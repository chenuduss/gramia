#ifndef COMPLETEDORDERARRAY_HPP
#define COMPLETEDORDERARRAY_HPP

#include "completedorder.hpp"
#include "baseorderarray.hpp"

namespace gramia {

class  CompletedOrderArray
        : public BaseOrderArray<CompletedOrder>
{
public:
    CompletedOrderArray();
    CompletedOrderArray(
            const BaseOrderArray<Order>& source,
            Trader::ID buyer = 0,
            bool anonymous = true,
            TradeSessionTimeStamp timestamp = 0);

    virtual ~CompletedOrderArray();

    /*void MarkAsCompleted(
            Trader::ID buyer,
            bool anonymous,
            TradeSessionTimeStamp timestamp);*/
};

}

#endif // COMPLETEDORDERARRAY_HPP
