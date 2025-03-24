class A {
public:
  int i;
  A(int n) : i(n) {}
};

class B {
public:
  int i;
  B(int n) : i(n) {}
};

void f(A a) {}
// void f(B b) {}

int main() {
  f(10);
  return 0;
}
