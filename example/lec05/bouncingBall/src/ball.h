#ifndef __BOUNCING_BALL_H__
#define __BOUNCING_BALL_H__

#include "app.h"
#include <raylib.h>

class Ball {
public:
  Ball(App* app, float x, float y, int r, Color color);
  void draw();
  void update(float delta);

private:
  float x, y, xSpeed, ySpeed;
  int r;
  Color color;
  App* app;
};

#endif