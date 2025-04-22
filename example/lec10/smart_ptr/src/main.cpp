#include "smart_ptr.hpp"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;

class A {
public:
  A() { cout << "Constructing A" << endl; }
  void print() const { cout << "printing" << endl; }

  ~A() { cout << "Destructing A" << endl; }
};

int main() {
  SmartPtr<int> p1(new int(42));
  cout << "p1 count: " << p1.useCount() << endl;

  {
    SmartPtr<int> p2 = p1;
    cout << "p1 count: " << p1.useCount() << endl;
  }
  cout << "p1 count: " << p1.useCount() << endl;

  SmartPtr<int> p3 = std::move(p1);
  cout << "p3 count: " << p3.useCount() << endl;
  cout << "p1 is null? " << (p1.get() == nullptr) << endl;

  cout << "Content of p3: " << *p3 << endl;

  SmartPtr<A> a{new A};

  {
    SmartPtr<A> a2 = a;
    cout << "a count: " << a.useCount() << endl;
  }
  cout << "a count: " << a.useCount() << endl;
  a->print();

  return 0;
}
