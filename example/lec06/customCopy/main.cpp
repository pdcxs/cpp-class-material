#include <iostream>

using namespace std;

class Student {
public:
  Student(const string &name, int age) : name(name), age(age) {
    cout << "Constructing Student " << name << endl;
  }
  Student(const Student &other) {
    cout << "Constructing copy of Student " << other.name << endl;
    name = other.name;
    age = other.age;
  }
  ~Student() { cout << "Destructing Student " << name << endl; }
  void setName(const string &name) { this->name = name; }

private:
  int age;
  string name;
};

int main() {
  Student s{"Eric", 12};
  Student s2{s};
  Student s3{"Alice", 20};
  s3 = s; // this will not call copy constructor
  s2.setName("Bob");
  return 0;
}
