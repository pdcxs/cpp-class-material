#include "myvector.h"
#include <sstream>

Vector::Vector(int size, int value) {
  m_size = size;
  m_capacity = std::max(size, 8);
  arr = new int[m_capacity];

  for (int i = 0; i < size; i++) {
    arr[i] = value;
  }
}

Vector::Vector(const Vector &other) {
  m_size = other.m_size;
  m_capacity = other.m_capacity;
  arr = new int[m_capacity];

  for (int i = 0; i < m_size; i++) {
    arr[i] = other.arr[i];
  }
}

Vector::Vector(Vector &&other) {
  m_size = other.m_size;
  m_capacity = other.m_capacity;
  arr = other.arr;
  other.arr = nullptr;
  other.m_size = 0;
  other.m_capacity = 0;
}

Vector::~Vector() { delete[] arr; }

std::string Vector::to_string() const {
  std::ostringstream oss;
  oss << "[";
  for (int i = 0; i < m_size - 1; i++) {
    oss << arr[i] << ", ";
  }
  if (m_size > 0) {
    oss << arr[m_size - 1];
  }

  oss << "]";
  return oss.str();
}
