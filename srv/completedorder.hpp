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
};

}

#endif // COMPLETEDORDER_HPP
