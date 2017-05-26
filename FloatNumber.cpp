#include <exception>

const unsigned Precision = 100000000;
class FloatNumber
{  
  unsigned long long _v;
public:
  FloatNumber(unsigned long long s)  
    : _v(s)
  {
  }

  FloatNumber(signed long long s)  
  {
    if (s < 0)
    {
      throw std::exception("ex3");
    }

    _v = s;
  }

  FloatNumber(signed s)      
  {
    if (s < 0)
    {
      throw std::exception("ex1");
    }

    _v = s;
  }

  FloatNumber(double s)      
  {
    if (s < 0)
    {
      throw std::exception("ex4");
    }

    s = s * Precision;

    _v = s;
  }

  FloatNumber() 
    : _v(0) 
  {
  }

  ~FloatNumber() {}

  FloatNumber operator + (const FloatNumber& v) const
  {
    return (_v + v._v);
  }

  FloatNumber operator - (const FloatNumber& v) const
  {
    if (v > *this)
    {
      throw std::exception("ex2");
    }

    return (_v - v._v);
  }

  bool operator < (const FloatNumber& v) const
  {
    return (_v < v._v);
  }

  bool operator < (signed long long s) const
  {
    if (s < 0)
    {
      return false;
    }

    return (_v < s);
  }

  bool operator > (const FloatNumber& v) const
  {
    return (_v > v._v);
  }

  bool operator == (const FloatNumber& v) const
  {
    return (_v == v._v);
  }

  bool operator != (const FloatNumber& v) const
  {
    return (_v != v._v);
  }

  FloatNumber operator * (const FloatNumber& v) const
  {
    double res = Get()*v.Get();
    return FloatNumber(res);
  }

  double Get() const
  {
    double v = _v;
    v = v/Precision;
    return v;
  }

private:  
};
