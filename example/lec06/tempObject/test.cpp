class A {
public:
  int i;
  A(int v) : i(v) {}
};

void f(A &&a) {}

int main() {
  f(12);
  return 0;
}
