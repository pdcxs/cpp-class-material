#ifndef __VECTOR_2D_H__
#define __VECTOR_2D_H__

#include <sstream>

class Vector2D {
private:
  double x, y;

public:
  Vector2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  Vector2D &add(const Vector2D other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  static Vector2D add(const Vector2D &v1, const Vector2D &v2) {
    Vector2D v(v1.x + v2.x, v1.y + v2.y);
    return v;
  }

  std::string to_string() const {
    std::ostringstream oss;
    oss << "{" << x << ", " << y << "}";
    return oss.str();
  }
};

#endif // !__VECTOR_2D_H__
