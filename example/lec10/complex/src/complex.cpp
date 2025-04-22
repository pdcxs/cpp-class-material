#include "complex.h"
#include <sstream>

Complex operator+(const Complex &c1, const Complex &c2) {
  return Complex::add(c1, c2);
}

Complex Complex::add(const Complex &c1, const Complex &c2) {
  Complex r;
  r.re = c1.re + c2.re;
  r.im = c1.im + c2.im;
  return r;
}

std::string Complex::to_string() const {
  std::ostringstream oss;
  oss << re << " + ";
  if (im != 0) {
    if (im != 1) {
      oss << im;
    }
    oss << "i";
  }
  return oss.str();
}
