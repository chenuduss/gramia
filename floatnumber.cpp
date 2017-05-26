#include "floatnumber.hpp"

#include <stdexcept>

FloatNumber::FloatNumber()
  : _v(0)
{
}


FloatNumber::FloatNumber(unsigned s)
{
  double x = s;
  _v = x * Precision;
}

FloatNumber::FloatNumber(signed s)
{
  if (s < FloatNumberMin)
  {
    throw std::range_error("less than zero");
  }

  double x = s;

  _v = x * Precision;
}

FloatNumber::FloatNumber(double s)
{
  if (s < 0)
  {
    throw std::range_error("less than zero");
  }

  if (s < 1/Precision)
  {
    throw std::range_error("too low precision");
  }

  if (s > FloatNumberMax)
  {
    throw std::range_error("too large number");
  }

  s = s * Precision;

  _v = s;
}

double FloatNumber::Get() const
{
  double v = _v;
  v = v/Precision;
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
        throw std::invalid_argument("big value");
    }

  return FromRaw(_v - v._v);
}

void FloatNumber::operator -= (const FloatNumber& v)
{
    if (v > *this)
    {
      throw std::invalid_argument("big value");
    }

    _v -= v._v;
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
