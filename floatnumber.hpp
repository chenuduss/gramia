#ifndef FLOATNUMBER_HPP
#define FLOATNUMBER_HPP

const unsigned FloatNumberMin = 0;
const unsigned long long FloatNumberMax = 4294967296;
const unsigned Precision = 100000000;

class FloatNumber
{
  unsigned long long _v;
public:
  FloatNumber(unsigned s);
  FloatNumber(signed s);
  FloatNumber(double s);
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

  double Get() const;

private:

  static FloatNumber FromRaw(unsigned long long s)
  {
    FloatNumber result;
    result._v = s;
    return result;
  }
};
#endif // FLOATNUMBER_HPP
