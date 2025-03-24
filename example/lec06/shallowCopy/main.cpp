// use following command to get right version:
// g++ -DRIGHT_VERSION ./main.cpp -g
// use following command to get wrong version:
// g++ ./main.cpp -g

#include <iostream>

using namespace std;

class Array {
public:
  explicit Array(int size) {
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
      arr[i] = 0;
  }
  Array(const Array &other) {
    this->size = other.size;
#ifndef RIGHT_VERSION
    this->arr = other.arr; // Don't do this-
#else
    this->arr = new int[size];
    for (int i = 0; i < size; i++)
      arr[i] = other.arr[i];
#endif
  }
  void set(int i, int value) { arr[i] = value; }
  int get(int i) const { return arr[i]; }
  void print() {
    cout << "[";
    for (int i = 0; i < size - 1; i++)
      cout << arr[i] << ", ";
    (size > 0 ? cout << arr[size - 1] : cout) << "]" << endl;
  }
  ~Array() { delete[] arr; }

private:
  int *arr;
  int size;
};

int main() {
  Array a{10};
  Array b = a;
  a.set(2, 100);
  a.print();
  b.print();
  return 0;
}
