#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <string>

class Complex {
public:
  Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}
  static Complex add(const Complex &c1, const Complex &c2);

  Complex &add(const Complex &other) {
    re += other.re;
    im += other.im;
    return *this;
  }

  Complex &operator+=(const Complex &other) {
    this->re += other.re;
    this->im += other.im;
    return *this;
  }

  std::string to_string() const;

private:
  double re, im;
};

Complex operator+(const Complex &c1, const Complex &c2);

#endif // !__COMPLEX_H__
