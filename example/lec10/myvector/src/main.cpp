#include "myvector.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Vector v;
  for (int i = 0; i < 20; i++) {
    v.pushBack(i);
  }

  cout << v.to_string() << endl;

  v.erase(3);
  cout << v.to_string() << endl;

  Vector v2;
  v2 = v;
  v2.pushBack(100);
  cout << v.to_string() << endl;
  cout << v2.to_string() << endl;

  return 0;
}
