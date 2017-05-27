#include "floatnumber.hpp"

#include <stdexcept>

//#include <iostream>

#include <cmath>
#include <cstdlib>

const FloatNumber FloatNumberOne(1.0);

FloatNumber::FloatNumber()
  : _v(0)
{
}


FloatNumber::FloatNumber(unsigned s)
{
  double x = s;
  _v = x * FloatNumberPrecision;
}

FloatNumber::FloatNumber(signed s)
{
  if (s < FloatNumberMin)
  {
    throw std::range_error("less than zero");
  }

  double x = s;

  _v = x * FloatNumberPrecision;
}

FloatNumber::FloatNumber(double s)
{
  if (s < 0)
  {
    throw std::range_error("less than zero");
  }

  if (s < 1/FloatNumberPrecision)
  {
    throw std::range_error("too low precision");
  }

  if (s > FloatNumberMax)
  {
    throw std::range_error("too large number");
  }

  s = s * FloatNumberPrecision;

  _v = s;
}

FloatNumber::FloatNumber(const char* s)
{
    std::string ss = s;
    int p = ss.find_first_of('.');
    if (p != std::string::npos)
    {
        int ca = FloatNumberPrecisionCount - (ss.size() - p - 1);
        if (ca > 0)
        {
            for (int i =0;i < ca; i++)
            {
                ss += "0";
            }
        }

        if (ca < 0)
        {
            ca = -ca;
            for (int i =0;i < ca; i++)
            {
                ss.erase(ss.begin() + (ss.size()-1));
            }
        }

        ss.erase(ss.begin()+p);
    }


    _v = std::strtoull(ss.c_str(), nullptr, 10);
}

double FloatNumber::Get() const
{
  double v = _v;
  v = v/FloatNumberPrecision;
  return v;
}


FloatNumber FloatNumber::operator + (const FloatNumber& v) const
{
  return FromRaw(_v + v._v);
}

FloatNumber FloatNumber::operator - (const FloatNumber& v) const
{
    if (v > *this)
    {
        throw std::invalid_argument("big value 1");
    }

  return FromRaw(_v - v._v);
}

void FloatNumber::operator -= (const FloatNumber& v)
{
    if (v > *this)
    {
      throw std::invalid_argument("big value 2");
    }

    _v -= v._v;
}

void FloatNumber::operator += (const FloatNumber& v)
{
    _v += v._v;
}

FloatNumber FloatNumber::operator / (const FloatNumber& v) const
{
  if (!v)
  {
    throw std::invalid_argument("zero delimiter");
  }

  double res = Get()/v.Get();
  return FloatNumber(res);
}

FloatNumber FloatNumber::GetInverted() const
{
    if (!*this)
    {
        return *this;
    }

    return FloatNumber(FloatNumberOne/(*this));
}

std::string FloatNumber::asString() const
{
    std::string result = std::to_string(_v);

    for (;result.size() < FloatNumberPrecisionCount+1;)
    {
        result = "0" + result;
    }

    int delimiterpos = result.size()-FloatNumberPrecisionCount;

    result.insert(delimiterpos, ".");

    return result;
}

void FloatNumber::ResetLastDigits(int c)
{
    double v = _v;
    for (int i = 0; i < c; i++) v = v/10;
    v = std::trunc(v);
    for (int i = 0; i < c; i++) v = v*10;
    _v = v;
}
