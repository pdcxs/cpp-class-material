#include <iostream>
#include <ostream>

class Complex {
public:
  Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

  friend Complex operator+(const Complex &c1, const Complex &c2);

  friend std::ostream &operator<<(std::ostream &out, const Complex &c);

private:
  double re, im;
};

Complex operator+(const Complex &c1, const Complex &c2) {
  return {c1.re + c2.re, c1.im + c2.im};
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
  if (c.re == 0 && c.im == 0) {
    out << 0;
    return out;
  }
  if (c.re != 0)
    out << c.re;
  if (c.im != 0) {
    if (c.re != 0)
      out << " + ";
    if (c.im != 1) {
      out << c.im;
    }
    out << "i";
  }
  return out;
}

int main(int argc, char **argv) {
  std::cout << Complex{1, 2} + Complex{-1, 2} << std::endl;
  std::cout << Complex{1, 0} << std::endl;
  std::cout << Complex{1, 1} << std::endl;
  std::cout << Complex{0, 1} << std::endl;
  std::cout << Complex{0, 4} << std::endl;
  std::cout << Complex{0, 0} << std::endl;
  return 0;
}
