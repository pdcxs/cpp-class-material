#include "app.h"
#include <box2d/box2d.h>
#include <box2d/math_functions.h>
#include <box2d/types.h>
#include <raylib.h>

int main() {
  App app(1000, 500, "Box2D Demo");
  app.run();
  return 0;
}
