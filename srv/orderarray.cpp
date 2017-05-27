#include "orderarray.hpp"

namespace gramia {

OrderArray::OrderArray()
{
}

OrderArray::~OrderArray()
{
}

StockVolume OrderArray::TotalVolume() const
{
    FloatNumber result;

    for (const auto& item: *this)
    {
        result += item.Volume;
    }

    return result;
}

StockPrice OrderArray::TotalValue() const
{
    FloatNumber result;

    for (const auto& item: *this)
    {
        result += item.GetValue();
    }

    return result;
}

}
