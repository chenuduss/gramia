#ifndef BASEORDERARRAY_H
#define BASEORDERARRAY_H

#include "stockvolume.hpp"
#include "stockprice.hpp"

#include <vector>

namespace gramia {

template<typename OrderType>
class BaseOrderArray
        : public std::vector<OrderType>
{
public:
    BaseOrderArray()
    {
    }

    ~BaseOrderArray()
    {
    }


    StockVolume TotalVolume() const
    {
        FloatNumber result;

        for (const auto& item: *this)
        {
            result += item.Volume;
        }

        return result;
    }

    StockPrice TotalValue() const
    {
        FloatNumber result;

        for (const auto& item: *this)
        {
            result += item.GetValue();
        }

        return result;
    }
};

}

#endif // ORDERARRAY_H
