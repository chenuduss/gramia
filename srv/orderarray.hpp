#ifndef ORDERARRAY_H
#define ORDERARRAY_H

#include "order.hpp"

#include <vector>

namespace gramia {

class OrderArray
        : public std::vector<Order>
{
public:
    OrderArray();
    ~OrderArray();

    StockVolume TotalVolume() const;
    StockPrice TotalValue() const;
};

}

#endif // ORDERARRAY_H
