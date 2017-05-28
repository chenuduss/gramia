#include "completedorderarray.hpp"

namespace  gramia
{

CompletedOrderArray::CompletedOrderArray()
{
}

CompletedOrderArray::CompletedOrderArray(
        const BaseOrderArray<Order> &source,
        Trader::ID buyer,
        bool anonymous,
        TradeSessionTimeStamp timestamp)
{
    for(const auto& item: source)
    {
       push_back(CompletedOrder(item, buyer, anonymous, timestamp));
    }
}

CompletedOrderArray::~CompletedOrderArray()
{

}

/*
void CompletedOrderArray::MarkAsCompleted(
        Trader::ID buyer,
        bool anonymous,
        TradeSessionTimeStamp timestamp)
{
    for(auto& item: *this)
    {
        item.Buyer = buyer;
        item.anonymous = anonymous;
        item.Completed = timestamp;
    }
}*/

}
