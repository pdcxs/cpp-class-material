#ifndef __RECT_H__
#define __RECT_H__

#include "raylib.h"
#include "raymath.h"
#include "shape.hpp"

class Rect : public Shape {
public:
  Rect(Vector2 pos, Vector2 vel, float size, Color color) {
    this->pos = pos;
    this->vel = vel;
    this->color = color;
    this->size = size;
  }
  void draw() const override { DrawRectangleV(pos, {size, size}, color); }

  void update(float delta) override {
    vel = Vector2Add(vel, Vector2Scale(acc, delta));
    pos = Vector2Add(pos, Vector2Scale(vel, delta));
  }

  bool isDead(int width, int height) const override {
    return pos.y > height + 100;
  }

  void applyForce(Vector2 force) override { acc = force; }

private:
  Vector2 pos, vel;
  Color color;
  float size;
  Vector2 acc;
};

#endif // !__RECT_H__
