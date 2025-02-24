#include <iostream>

int main() {
  int a = 100, b = 10;
  int *pointer_1, *pointer_2;

  pointer_1 = &a;
  pointer_2 = &b;
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "*pointer_1 = " << *pointer_1 << ", *pointer_2 = " << *pointer_2
            << std::endl;

  return 0;
}
