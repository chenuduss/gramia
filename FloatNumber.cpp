#include <iostream>

#include <exception>

const unsigned FloatNumberMin = 0;
const unsigned long long FloatNumberMax = 4294967296;
const unsigned Precision = 100000000;
class FloatNumber
{  
  unsigned long long _v;
public:
  FloatNumber(unsigned s)  
  {
    _v = s * Precision;
  }

  FloatNumber(signed s)  
  {
    if (s < FloatNumberMin)
    {
      throw std::exception("ex3");
    }

    _v = s * Precision;
  }

  FloatNumber(double s)      
  {
    if (s < 0)
    {
      throw std::exception("ex4");
    }

    if (s < 1/Precision)
    {
      throw std::exception("ex6");
    }

    if (s > FloatNumberMax)
    {
      throw std::exception("ex7");
    }

    s = s * Precision;

    _v = s;
  }

  FloatNumber() 
    : _v(0) 
  {
  }

  ~FloatNumber() {}

  operator bool () const
  {
    return (_v != 0);
  }

  FloatNumber operator + (const FloatNumber& v) const
  {
    return FromRaw(_v + v._v);
  }

  FloatNumber operator - (const FloatNumber& v) const
  {
    if (v > *this)
    {
      throw std::exception("ex2");
    }

    return FromRaw(_v - v._v);
  }

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

  bool operator != (const FloatNumber& v) const
  {
    return (_v != v._v);
  }

  FloatNumber operator * (const FloatNumber& v) const
  {
    double res = Get()*v.Get();
    return FloatNumber(res);
  }

  FloatNumber operator / (const FloatNumber& v) const
  {
    if (!v)
    {
      throw std::exception("ex5");
    }

    double res = Get()/v.Get();
    return FloatNumber(res);
  }

  double Get() const
  {
    double v = _v;
    v = v/Precision;
    return v;
  }

private:  
  static FloatNumber FromRaw(unsigned long long s)
  {
    FloatNumber result;
    result._v = s;
    return result;
  }
};


int _tmain(int argc, _TCHAR* argv[])
{
  FloatNumber x(5);
  FloatNumber y(3);
  FloatNumber x1 = x / y;
  FloatNumber x2 = x / y;
  FloatNumber x3 = x / y;

  std::cout.unsetf ( std::ios::floatfield );   
  std::cout.precision(8);
  std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 

  x = x1 + x2 + x3;
  std::cout << x.Get() << std::endl;
  FloatNumber x4(500);
  FloatNumber x5 = x4 / x; 
  std::cout << x5.Get() << std::endl;


  FloatNumber xxx = x * FloatNumber(2);
  
  FloatNumber xxx2 = xxx - FloatNumber(9.999900000);
  std::cout << xxx.Get();

  return 0;
}