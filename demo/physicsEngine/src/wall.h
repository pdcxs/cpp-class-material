#pragma once

#include <box2d/box2d.h>
#include <box2d/id.h>
#include <raylib.h>

class Wall {
public:
  Wall(b2WorldId worldId, Vector2 pos, Vector2 size, float angle);
  void draw();

private:
  Vector2 pos, size;
  float angle;
  b2BodyId bodyId;
};
