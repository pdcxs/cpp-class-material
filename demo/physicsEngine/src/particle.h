#pragma once

#include <raylib.h>

class Particle {
public:
  virtual void draw() = 0;
  virtual Vector2 getPos() = 0;
};
