#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "trader.hpp"
#include "stock.hpp"

#include <vector>

namespace gramia
{

class Transaction
{
public:
    Transaction();
    ~Transaction() {}

    stock sold;
    double volume; //
    double price;  // price in other stock for 1.0 of sold stock
    Trader::ID seller;
    Trader::ID buyer;
};

typedef std::vector<Transaction> TransactionList;

}

#endif // TRANSACTION_HPP
