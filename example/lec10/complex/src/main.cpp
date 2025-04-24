#include "complex.h"
#include <iostream>

int main() {
  Complex c1{1, 2};
  Complex c2{3, 4};
  auto c3 = c1 + c2;
  std::cout << c3.to_string() << std::endl;

  (c3 += c1) += c2;
  c3.add(c1).add(c2);
  std::cout << c3.to_string() << std::endl;
  return 0;
}
