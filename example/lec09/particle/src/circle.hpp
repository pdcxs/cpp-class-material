#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "raylib.h"
#include "raymath.h"
#include "shape.hpp"

class Circle : public Shape {
public:
  Circle(Vector2 pos, Vector2 vel, float radius, Color color) {
    this->pos = pos;
    this->vel = vel;
    this->color = color;
    this->radius = radius;
  }

  void draw() const override { DrawCircleV(pos, radius, color); }

  void update(float delta) override {
    vel = Vector2Add(vel, Vector2Scale(acc, delta));
    pos = Vector2Add(pos, Vector2Scale(vel, delta));
    // std::cout << pos.x << ", " << pos.y << std::endl;
  }

  bool isDead(int width, int height) const override {
    return pos.y > height + 100;
  }

  void applyForce(Vector2 force) override { acc = force; }

private:
  Vector2 pos, vel;
  Color color;
  float radius;
  Vector2 acc;
};

#endif // !__CIRCLE_H__
