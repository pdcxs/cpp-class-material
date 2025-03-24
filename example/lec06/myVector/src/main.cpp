#include "myvector.h"
#include <iostream>
#include <utility>

int main(int argc, char **argv) {
  Vector v{10, 2};
  Vector v2(std::move(v));
  std::cout << v.to_string() << std::endl;
  std::cout << v2.to_string() << std::endl;
  return 0;

  // std::unique_ptr
}
