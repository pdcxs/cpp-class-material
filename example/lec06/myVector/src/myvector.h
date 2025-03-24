#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <string>

class Vector {
public:
  Vector(int size = 0, int value = 0);
  Vector(const Vector &other);
  Vector(Vector &&other);

  ~Vector();

  std::string to_string() const;

private:
  int *arr;
  int m_capacity;
  int m_size;
};

#endif // !__MY_VECTOR_H__
