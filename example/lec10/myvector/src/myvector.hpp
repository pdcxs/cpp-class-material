#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <cstdlib>
#include <sstream>
#include <string>
class Vector {
  using Elem = int;
  unsigned int capacity;
  unsigned int size;
  Elem *content;

public:
  Vector() {
    capacity = 8;
    size = 0;
    content = new Elem[size];
  }

  Vector(const Vector &other) { copy(other); }

  Vector(Vector &&other) { move((Vector &&)other); }

  Vector &operator=(const Vector &other) {
    copy(other);
    return *this;
  }

  Vector &operator=(Vector &&other) {
    move((Vector &&)other);
    return *this;
  }

  void pushBack(const Elem &elem) {
    if (size == capacity)
      grow();
    content[size] = elem;
    size += 1;
  }

  void erase(int index) {
    if (index < 0 || index >= size) {
      return;
    }

    if (size == 0)
      return;

    for (int i = index; i < size - 1; i++) {
      content[i] = content[i + 1];
    }
    size -= 1;
  }

  bool isEmpty() const { return size == 0; }

  std::string to_string() const {
    std::ostringstream oss;
    oss << "[";
    for (int i = 0; i < size - 1; i++) {
      oss << content[i] << ", ";
    }
    if (size > 0) {
      oss << content[size - 1];
    }
    oss << "]";
    return oss.str();
  }

  int getSize() const { return size; }

  ~Vector() {
    if (content != nullptr)
      delete[] content;
  }

private:
  void copy(const Vector &other) {
    if (&other == this)
      return;
    size = other.size;
    capacity = size;
    delete[] content;
    content = new Elem[size];
    for (int i = 0; i < size; i++) {
      content[i] = other.content[i];
    }
  }

  void move(Vector &&other) {
    if (&other == this)
      return;
    delete[] content;
    size = other.size;
    capacity = other.capacity;
    content = other.content;
    other.content = nullptr;
  }

  void grow() {
    if (capacity == 0)
      capacity = 1;
    else
      capacity *= 2;

    Elem *newContent = new Elem[capacity];
    for (int i = 0; i < size; i++) {
      newContent[i] = content[i];
    }
    delete content;
    content = newContent;
  }
};

#endif // !__MY_VECTOR_H__
