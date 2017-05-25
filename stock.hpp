#ifndef STOCK_HPP
#define STOCK_HPP

namespace gramia
{

enum stock
{
    st1 = 0,
    st2
};

typedef double StockPrice;
typedef double StockVolume;

inline stock GetOther(stock s) {return (s == st1) ? st2 : st1;}

}

#endif // STOCK_HPP
