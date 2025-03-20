#include "wall.h"
#include <box2d/box2d.h>
#include <box2d/collision.h>
#include <box2d/id.h>
#include <box2d/math_functions.h>
#include <box2d/types.h>
#include <raylib.h>

Wall::Wall(b2WorldId worldId, Vector2 pos, Vector2 size, float angle)
    : pos(pos), size(size), angle(angle) {
  b2BodyDef bodyDef = b2DefaultBodyDef();
  bodyDef.position = {pos.x, pos.y};
  bodyDef.rotation = b2MakeRot(angle * PI / 180.0f);
  bodyId = b2CreateBody(worldId, &bodyDef);

  b2Polygon box = b2MakeBox(size.x / 2.0f, size.y / 2.0f);
  b2ShapeDef shapeDef = b2DefaultShapeDef();
  b2CreatePolygonShape(bodyId, &shapeDef, &box);
}

void Wall::draw() {
  Rectangle rec;
  rec.width = size.x;
  rec.height = size.y;
  rec.x = pos.x;
  rec.y = pos.y;
  DrawRectanglePro(rec, {size.x / 2.0f, size.y / 2.0f}, angle, BLACK);
}
