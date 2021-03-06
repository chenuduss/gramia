#ifndef STOCK_HPP
#define STOCK_HPP

#include "stockprice.hpp"
#include "stockvolume.hpp"

namespace gramia
{

enum stock
{
	stInvalid = 0,
    st1,
    st2
};

inline stock GetOther(stock s) {return (s == st1) ? st2 : st1;}

}

#endif // STOCK_HPP
