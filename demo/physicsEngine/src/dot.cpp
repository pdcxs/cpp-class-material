#include "dot.h"
#include <box2d/box2d.h>
#include <box2d/collision.h>
#include <box2d/id.h>
#include <box2d/types.h>
#include <raylib.h>

Dot::Dot(b2WorldId worldId, Vector2 pos, float radius, Color color) {
  this->radius = radius;
  this->color = color;

  b2BodyDef bodyDef = b2DefaultBodyDef();
  bodyDef.type = b2_dynamicBody;
  bodyDef.position = {pos.x, pos.y};

  bodyId = b2CreateBody(worldId, &bodyDef);

  b2ShapeDef shapeDef = b2DefaultShapeDef();
  shapeDef.density = 1.0f;

  b2Circle circle;
  circle.center = {0.0f, 0.0f};
  circle.radius = radius;

  b2ShapeId circleShapeId = b2CreateCircleShape(bodyId, &shapeDef, &circle);
  b2Shape_SetFriction(circleShapeId, 0.0);
}

void Dot::draw() {
  b2Vec2 position = b2Body_GetPosition(bodyId);
  DrawCircle(position.x, position.y, radius, color);
}

Vector2 Dot::getPos() {
  b2Vec2 pos = b2Body_GetPosition(bodyId);
  return {pos.x, pos.y};
}
