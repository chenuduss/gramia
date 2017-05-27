#include <iostream>


#include "../srv/orderlist.hpp"

#include <random>

FloatNumber failmaxpart = 10000;

bool TestOrderList(
        unsigned i1,
        unsigned i2)
{
    gramia::OrderList ol;

    FloatNumber t1;

    FloatNumber v1 = 5;
    v1 = v1 / i1;

    gramia::Order o1(gramia::st1, 45, v1, FloatNumber(6.4));
    ol.AddOrder(o1);
    t1 += v1;

    v1 += 6;
    v1  = v1 / i1;


    gramia::Order o2(gramia::st1, 0, v1, FloatNumber(6.5), 0, 56);
    ol.AddOrder(o2);
    t1 += v1;

    FloatNumber t2 = t1;

    v1 += 7;
    v1  = v1 / i1;

    gramia::Order o3(gramia::st1, 0, v1, FloatNumber(6.6), 0, 56);
    ol.AddOrder(o3);
    t1 += v1;

    if (ol.Count() != 3)
    {
        return false;
    }

    FloatNumber tv = ol.TotalVolume(FloatNumber(6.7));
    FloatNumber tv2 = ol.TotalVolume(FloatNumber(6.51));

    if (t1 != tv)
    {
        std::cout << t1.Get() << " (t1 != tv) " << tv.Get() << std::endl;
        return false;
    }

    if (t2 != tv2)
    {
        return false;
    }

    FloatNumber div(i2);
    FloatNumber buyvalue(o1.GetValue()/div);

    gramia::OrderResult oa;

    oa = ol.PullOutOrders(FloatNumber(6.5), buyvalue);

    if (!oa.Completed)
    {
        return false;
    }

    FloatNumber t3 = oa.Orders.TotalValue();

    if (t3 > buyvalue)
    {
        std::cout << t3.Get() << " (t3 > buyvalue) " << buyvalue.Get() << std::endl;
        return false;
    }

    FloatNumber t4 = buyvalue - t3;
    FloatNumber maxfail = buyvalue/failmaxpart;

    if (t4 > maxfail)
    {
        ///std::cout << t4.Get() << " (t4 > maxfail) " << maxfail.Get() << std::endl;
        return false;
    }

    ol.CancelOrder(45, 0);

    if (ol.Count() != 2)
    {
        return false;
    }

    ol.CancelOrdersByOwner(56);

    if (ol.Count())
    {
        return false;
    }


    return true;
}


bool TestOrderListStr(
        const std::string& i4,
        const std::string& i5,
        const std::string& i6,
        unsigned i2)
{
    gramia::OrderList ol;

    FloatNumber t1;

    FloatNumber v1 = FloatNumber(i4.c_str());

    gramia::Order o1(gramia::st1, 45, v1, FloatNumber(6.4));
    ol.AddOrder(o1);
    t1 += v1;

    v1  = FloatNumber(i5.c_str());


    gramia::Order o2(gramia::st1, 0, v1, FloatNumber(6.5), 0, 56);
    ol.AddOrder(o2);
    t1 += v1;

    FloatNumber t2 = t1;

    v1  = FloatNumber(i6.c_str());


    gramia::Order o3(gramia::st1, 0, v1, FloatNumber(6.6), 0, 56);
    ol.AddOrder(o3);
    t1 += v1;

    if (ol.Count() != 3)
    {
        return false;
    }

    FloatNumber tv = ol.TotalVolume(FloatNumber(6.7));
    FloatNumber tv2 = ol.TotalVolume(FloatNumber(6.51));

    if (t1 != tv)
    {
        std::cout << t1.Get() << " (t1 != tv) " << tv.Get() << std::endl;
        return false;
    }

    if (t2 != tv2)
    {
        return false;
    }

    FloatNumber div(i2);
    FloatNumber buyvalue(o1.GetValue()/div);

    gramia::OrderResult oa;

    oa = ol.PullOutOrders(FloatNumber(6.5), buyvalue);

    if (!oa.Completed)
    {
        std::cout << "if (!oa.Completed)  "<< buyvalue.asString() << " orderval " << o1.GetValue().asString() << std::endl;
        return false;
    }

    FloatNumber t3 = oa.Orders.TotalValue();

    if (t3 > buyvalue)
    {
        std::cout << t3.Get() << " (t3 > buyvalue) " << buyvalue.Get() << std::endl;
        return false;
    }

    FloatNumber t4 = buyvalue - t3;
    FloatNumber maxfail = buyvalue/failmaxpart;

    if (t4 > maxfail)
    {
        std::cout << t4.Get() << " (t4 > maxfail) " << maxfail.Get() << std::endl;
        return false;
    }

    ol.CancelOrder(45, 0);

    if (ol.Count() != 2)
    {
        std::cout << "ol.Count() != 2 " << std::endl;
        return false;
    }

    ol.CancelOrdersByOwner(56);

    if (ol.Count())
    {
        std::cout << "ol.Count()) " << std::endl;
        return false;
    }


    return true;
}

std::default_random_engine gen(std::random_device{}());
std::uniform_int_distribution<char> numbers('0', '9');
std::uniform_int_distribution<int> sizes1(1, 3);
std::uniform_int_distribution<int> sizes2(2, 5);

std::string getnumbers(std::uniform_int_distribution<int>& lendistr)
{
    std::string result;
    int len = lendistr(gen);

    for (int i = 0; i < len; i++)
    {
        result += numbers(gen);
    }


    return result;
}

std::string getnumber()
{
    std::string result;

    result = getnumbers(sizes1);
    if ((result == "0") || (result == "00") || (result == "000"))
    {
        result = "1";
    }




    result += "." + getnumbers(sizes2);

    return result;
}

int main()
{
    std::cout.unsetf ( std::ios::floatfield );
    std::cout.precision(9);
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );

    /*FloatNumber v1("45.065237");
    FloatNumber v2("0.0005");
    FloatNumber v3("1.098323231");
    FloatNumber v4("1.09832327792382323232435453453453");
    std::cout << v1.Get()<< "  " << v1.asString()  << std::endl;
    std::cout << v2.Get()<< "  " << v2.asString()  << std::endl;
    std::cout << v3.Get()<< "  " << v3.asString()  << std::endl;
    std::cout << v4.Get()<< "  " << v4.asString()  << std::endl;
    return 0;*/



    unsigned total = 0;
    unsigned success = 0;
    for (unsigned i = 1; i < 1001; i++)
    {
        for (unsigned j = 1; j < 1001; j++)
        {
            if (TestOrderList(i, j))
            {
                ++success;
            }
            ++total;
        }
    }

    std::cout << "TESTS: " << success<< " / " <<  total << " | ERRORS: "<< ((double)(total - success)/(double)total)*100 << " % "<< std::endl;




    total = 0;
    success = 0;
    for (unsigned i = 1; i < 1001; i++)
    {
        for (unsigned j = 1; j < 1001; j++)
        {
            std::string s1, s2, s3;

            s1 = getnumber();
            s2 = getnumber();
            s3 = getnumber();

            if (TestOrderListStr(s1, s2, s3, j))
            {
                ++success;
            }
            ++total;
        }
    }

    std::cout << "TESTS STR: " << success<< " / " <<  total << std::endl;


    return 0;
}

