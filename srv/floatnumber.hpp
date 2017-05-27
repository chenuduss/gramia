#ifndef FLOATNUMBER_HPP
#define FLOATNUMBER_HPP

const unsigned FloatNumberMin = 0;
const unsigned long long FloatNumberMax = 4294967296;
const unsigned FloatNumberPrecisionCount = 9;
const unsigned FloatNumberPrecision = 1000000000;

#include <string>

class FloatNumber
{
  unsigned long long _v;
public:
  FloatNumber(unsigned s);
  FloatNumber(signed s);
  FloatNumber(double s);
  FloatNumber(
          const char* s,
          int precision = FloatNumberPrecisionCount);
  FloatNumber();
  ~FloatNumber()
  {
  }

  operator bool () const
  {
    return (_v != 0);
  }

  FloatNumber operator + (const FloatNumber& v) const;
  FloatNumber operator - (const FloatNumber& v) const;
  void operator -= (const FloatNumber& v);
  void operator += (const FloatNumber& v);

  bool operator < (const FloatNumber& v) const
  {
    return (_v < v._v);
  }

  bool operator < (signed s) const
  {
    if (s < 0)
    {
      return false;
    }

    return (_v < s);
  }

  bool operator <= (const FloatNumber& v) const
  {
    return (*this < v) || (*this == v);
  }


  bool operator > (const FloatNumber& v) const
  {
    return (_v > v._v);
  }

  bool operator == (const FloatNumber& v) const
  {
    return (_v == v._v);
  }

  bool operator == (double v) const
  {
    return (*this == FloatNumber(v));
  }

  bool operator != (const FloatNumber& v) const
  {
    return (_v != v._v);
  }

  bool operator != (signed v) const
  {
    return (*this != FloatNumber(v));
  }

  FloatNumber operator * (const FloatNumber& v) const
  {
    double res = Get()*v.Get();
    return FloatNumber(res);
  }  

  FloatNumber operator / (const FloatNumber& v) const;
  FloatNumber operator / (unsigned v) const
  {
    return operator /(FloatNumber(v));
  }

  double Get() const;

  FloatNumber GetInverted() const;


  void ResetLastDigits(int c = 1);


  std::string asString() const;
private:

  static FloatNumber FromRaw(unsigned long long s)
  {
    FloatNumber result;
    result._v = s;
    return result;
  }
};

#endif // FLOATNUMBER_HPP
