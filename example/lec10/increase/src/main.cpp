#include <iostream>
using namespace std;

class Increase {
  int value;

public:
  Increase(int x) : value(x) {}
  Increase &operator++() { // 前增量(无参数)
    value++;               // 先增量
    return *this;          // 返回原对象
  }

  Increase operator++(int) {
    // 后增量(仅一标记参数int)
    Increase temp(value);
    // 构造临时对象存放原对象值
    value++;     // 原有对象值改变
    return temp; // 返回原对象值
  }

  void display() { cout << "the value is " << value << endl; }
};

int main() {
  Increase n(20);
  n.display();

  (n++ ++).display();
  n.display();

  ++(++n);
  n.display();
  return 0;
}
