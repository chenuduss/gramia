#ifndef EXCHANGEENGINE_HPP
#define EXCHANGEENGINE_HPP


#include "exchangecore.hpp"

namespace gramia
{

class ExchangeEngine
{
public:
    ExchangeEngine();
    ~ExchangeEngine() {}

protected:
    ExchangeCore m_Core;

};

}

#endif // EXCHANGEENGINE_HPP
