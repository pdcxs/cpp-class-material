#include "cons.h"
#include <iostream>

using namespace conslist;

int main(int argc, char **argv) {
  auto lst = cons(3, cons(2, cons(1, nullptr)));
  print(lst);
  std::cout << std::endl;

  std::cout << "length: " << length(lst) << std::endl;
  print(map(lst, [](int x) { return x * x; }));

  std::cout << std::endl;

  return 0;
}
