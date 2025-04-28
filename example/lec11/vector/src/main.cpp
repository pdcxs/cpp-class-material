#include "vector.hpp"
#include <algorithm>
#include <iostream>

using myvector::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
  vector<string> strs;
  cout << "initial str vector: " << strs << endl;

  strs.push_back("hello");
  strs.push_back("world");

  for (auto &elem : strs)
    cout << elem << endl;

  vector<int> ints;
  ints.push_back(3);
  ints.push_back(0);
  ints.push_back(2);
  ints.push_back(1);

  cout << "int vector before sorting: " << ints << endl;
  std::sort(ints.begin(), ints.end());
  cout << "int vector after sorting: " << ints << endl;

  // initializer
  vector<double> dvec1(3, 10);
  cout << "dvec1: " << dvec1 << endl;
  vector<double> dvec2{3, 10};
  cout << "dvec2: " << dvec2 << endl;

  // const iterator
  auto const &cref = dvec1;
  // for(auto &p : cref) {
  //   p += 2;
  // }
  for (auto &p : dvec1) {
    p += 2;
  }
  // for (auto const& p : dvec1) {
  //   p += 2;
  // }
  for (auto &p : cref) {
    cout << p << ", ";
  }
  cout << endl;

  return 0;
}
