#include "orderlist.hpp"

#include <stdexcept>

namespace gramia
{

OrderList::OrderList()
{
}

void OrderList::AddOrder(const Order& o)
{
    OrderContainer::const_iterator iter = m_Container.cbegin();
    for (; iter != m_Container.cend(); iter++)
    {
        if (o.Price < iter->Price)
        {
            break;
        }
    }

    m_Container.insert(iter, o);
}

OrderList::OrderContainer::const_iterator OrderList::FindOrder(Order::ID id) const
{
    for (OrderContainer::const_iterator iter = m_Container.cbegin(); iter != m_Container.cend(); iter++)
    {
        if (id == iter->Id)
        {
            return iter;
        }
    }

    return m_Container.cend();
}

bool OrderList::IsExist(Order::ID id) const noexcept
{
    return (FindOrder(id) != m_Container.cend());
}

Order OrderList::CancelOrder(Order::ID id)
{
    OrderContainer::const_iterator iter = FindOrder(id);
    if (iter  == m_Container.cend())
    {
        return Order::GetEmpty();
    }
    Order result(*iter);

    m_Container.erase(iter);

    return result;

}

OrderArray OrderList::CancelOrdersByCreator(Trader::ID tr)
{
    OrderArray result;

    for (OrderContainer::const_iterator iter = m_Container.cbegin(); iter != m_Container.cend(); )
    {
        if (tr == iter->Creator)
        {
            result.push_back(*iter);
            iter = m_Container.erase(iter);
        }   else
        {
            iter++;
        }
    }

    return result;
}

OrderArray OrderList::PullOutOrders(StockPrice price, StockPrice value)
{
    OrderArray result;

    for (OrderContainer::iterator iter = m_Container.begin(); (iter != m_Container.end()) && (value != 0); )
    {
        if (price > iter->Price)
        {
            break;
        }

        FloatNumber val = iter->GetValue();

        if (val <= value)
        {
            result.push_back(*iter);
            iter = m_Container.erase(iter);
            value -= val;
        }   else
        {
            FloatNumber cvol = value / price;\
            if (cvol > iter->Volume)
            {
                throw std::runtime_error("FloatNumber bug (1) (OrderList::PullOutOrders)");
            }\

            result.push_back(iter->Cut(cvol));

            if (iter->empty())
            {
                m_Container.erase(iter);
            }

            if (result.cbegin()->GetValue() != value)
            {
                throw std::runtime_error("FloatNumber bug (2) (OrderList::PullOutOrders)");
            }

            break;
        }
    }

    return result;
}


}
