#include "orderlist.hpp"

#include <stdexcept>


//#include <iostream>

namespace gramia
{

OrderList::OrderList()
{
}

OrderList::~OrderList()
{
}

void OrderList::AddOrder(const Order& o)
{
    if (o.Volume < StockVolumeMin)
    {
        throw std::range_error("Too small volume (OrderList::AddOrder)");
    }

    if (o.Volume > StockVolumeMax)
    {
        throw std::range_error("Too big volume (OrderList::AddOrder)");
    }

    if (o.Price < StockPriceMin)
    {
        throw std::range_error("Too small price (OrderList::AddOrder)");
    }

    if (o.Price > StockPriceMax)
    {
        throw std::range_error("Too big price (OrderList::AddOrder)");
    }

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

OrderResult OrderList::PullOutOrders(StockPrice price, StockPrice value)
{
    OrderResult result;

    //std::cout << "PullOutOrders :: " << price.Get() << " , " << value.Get() << std::endl;

    for (OrderContainer::iterator iter = m_Container.begin(); (iter != m_Container.end()) && (value != 0); )
    {
        if (price < iter->Price)
        {
            break;
        }

        FloatNumber val = iter->GetValue();

        //std::cout << "PullOutOrders :: " << iter->Price.Get() << " , " << iter->Volume.Get() << " , " << val.Get() << std::endl;



        if (val < value)
        {
            result.Orders.push_back(*iter);
            iter = m_Container.erase(iter);
            value -= val;
        }   else
        {
            //std::cout << "precheck1 : " << val.Get() << " > " << value.Get() << std::endl;

            FloatNumber cvol = value / iter->Price;\

            //std::cout << "precheck2 : " << cvol.Get() << " = " << value.Get() << " / "<< price.Get() << std::endl;

            if (cvol > iter->Volume)
            {
                throw std::runtime_error("FloatNumber bug (1) (OrderList::PullOutOrders)");
            }\

            //std::cout << "precheck3 : volume " << iter->Volume.Get() << std::endl;

            result.Orders.push_back(iter->Cut(cvol));

            //std::cout << "precheck3 : volume after cut " << iter->Volume.Get() << std::endl;

            if (iter->empty())
            {
                m_Container.erase(iter);
            }            

            result.Completed = true;
            value -= result.Orders.crbegin()->GetValue();

            break;
        }
    }

    result.RemainValue = value;

    return result;
}

StockPrice OrderList::TotalVolume(StockPrice target) const
{
    StockPrice result;

    for (OrderContainer::const_iterator iter = m_Container.cbegin(); (iter != m_Container.cend()); iter++)
    {
        if (target < iter->Price)
        {
            break;
        }

        //std::cout <<"TotalVolume: " << iter->Volume.Get() << std::endl;
        result += iter->Volume;
    }

    return result;
}

StockPrice OrderList::TotalValue(StockPrice target) const
{
    StockPrice result;

    for (OrderContainer::const_iterator iter = m_Container.cbegin(); (iter != m_Container.cend()); iter++)
    {
        if (target < iter->Price)
        {
            break;
        }


        result += iter->GetValue();
    }

    return result;
}


}
