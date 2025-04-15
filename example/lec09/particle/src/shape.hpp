#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "raylib.h"

class Shape {
public:
  virtual void draw() const = 0;
  virtual void update(float delta) = 0;
  virtual bool isDead(int width, int height) const = 0;
  virtual void applyForce(Vector2 force) = 0;
};

#endif // !__SHAPE_H__
