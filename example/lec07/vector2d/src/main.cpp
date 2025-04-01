#include "vector2d.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv) {
  Vector2D v;
  v.add({1, 2}).add({3, 4});
  cout << v.to_string() << endl;

  Vector2D v2{100, 200};
  Vector2D v3 = Vector2D::add(v, v2);
  cout << v3.to_string() << endl;
  cout << v.to_string() << endl;
  cout << v2.to_string() << endl;
  return 0;
}
