#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <ostream>
#include <string>

class Complex {
public:
  Complex(double r = 0.0, double i = 0.0);

  static Complex add(const Complex &, const Complex &);

  Complex &add(const Complex &other);

  Complex &operator+=(const Complex &other);

  std::string to_string() const;

private:
  double re, im;
};

Complex operator+(const Complex &c1, const Complex &c2);

std::ostream &operator<<(std::ostream &, const Complex &);

#endif // !__COMPLEX_H__
