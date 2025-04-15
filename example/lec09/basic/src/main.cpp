#include <iostream>

using std::cout;
using std::endl;

class Animal {
public:
  virtual void bark() const {
    cout << "Some animal is barking!" << endl;
  }
};

class Dog : public Animal {
public:
  void bark() const {
    cout << "Wang wang!" << endl;
  }
};

class Puppy : public Dog {
public:
  void bark() const {
    cout << "Mew Mew" << endl;
  }
};

void bark(Animal* animal) {
  animal->bark();
}

int main(int argc, char** argv) {
  Animal *animal;
  int i;
  std::cin >> i;
  if (i == 0) {
    animal = new Dog();
  } else if (i == 1) {
    animal = new Puppy();
  } else {
    animal = new Animal();
  }
  animal->bark();
  delete animal;

  Dog dog;
  bark(&dog);
  return 0;
}
