#include "complex.h"
#include <sstream>

Complex operator+(const Complex &c1, const Complex &c2) {
  return Complex::add(c1, c2);
}

Complex::Complex(double r, double i) : re(r), im(i) {}

Complex Complex::add(const Complex &c1, const Complex &c2) {
  Complex r;
  r.re = c1.re + c2.re;
  r.im = c1.im + c2.im;
  return r;
}

Complex &Complex::add(const Complex &other) {
  re += other.re;
  im += other.im;
  return *this;
}

Complex &Complex::operator+=(const Complex &other) {
  re += other.re;
  im += other.im;
  return *this;
}

std::string Complex::to_string() const {
  if (re == 0 && im == 0) {
    return "0";
  }
  std::ostringstream oss;
  if (re != 0) {
    oss << re;
    if (im != 0) {
      oss << " + ";
    }
  }
  if (im != 0) {
    if (im != 1) {
      oss << im;
    }
    oss << "i";
  }
  return oss.str();
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
  return out << c.to_string();
}
