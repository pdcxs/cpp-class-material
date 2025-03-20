#pragma once

#include "particle.h"
#include <box2d/id.h>
#include <raylib.h>

class Dot : public Particle {
public:
  Dot(b2WorldId worldId, Vector2 pos, float radius, Color color);
  void draw() override;
  Vector2 getPos() override;

private:
  Color color;
  float radius;
  b2BodyId bodyId;
};
