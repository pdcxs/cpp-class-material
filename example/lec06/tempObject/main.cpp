// c++ 会有返回值优化，可以用以下命令关闭，以查看效果
// g++ -fno-elide-constructors ./main.cpp
#include <iostream>

using namespace std;

class A {
public:
  A(string id) : id(id) { cout << "Constructing A with id " << id << endl; }
  A(const A &other) : id(other.id) { cout << "Copy " << other.id << endl; }

  string id;
};

A returnValueFunc(A a) {
  A b = a;
  return b; // 如果没有返回值优化，此处会发生拷贝
}

int main() {
  A a("a1");
  A b = a;
  A c = returnValueFunc(b);
  A d = A("d");
  A e = returnValueFunc(A("temp"));
  return 0;
}
