#include "ball.h"
#include <cmath>

Ball::Ball(App *app, float x, float y, int r, Color color) : color(color) {
  this->x = x;
  this->y = y;
  this->r = r;
  xSpeed = GetRandomValue(60, 120);
  ySpeed = GetRandomValue(60, 120);
  this->app = app;
}
void Ball::draw() { DrawCircle(x, y, r, color); }
void Ball::update(float delta) {
  x += xSpeed * delta;
  y += ySpeed * delta;
  ySpeed += 200 * delta;
  if (x - r < 10) {
    x = 10 + r;
    app->applyCamSpeed(-xSpeed, 0);
    float v = std::abs(xSpeed / 200);
    v = v < 1.0 ? v : 1.0;
    SetSoundVolume(app->collisionSound, v);
    PlaySound(app->collisionSound);
    xSpeed *= -0.9;
  }
  if (x + r > app->getWidth() - 10) {
    x = app->getWidth() - r - 10;
    app->applyCamSpeed(-xSpeed, 0);
    float v = std::abs(xSpeed / 200);
    v = v < 1.0 ? v : 1.0;
    SetSoundVolume(app->collisionSound, v);
    PlaySound(app->collisionSound);
    xSpeed *= -0.9;
  }
  if (y - r < 10) {
    y = 10 + r;
    app->applyCamSpeed(0, -ySpeed);
    float v = std::abs(ySpeed / 200);
    v = v < 1.0 ? v : 1.0;
    SetSoundVolume(app->collisionSound, v);
    PlaySound(app->collisionSound);
    ySpeed *= -1;
  }
  if (y + r > app->getHeight() - 10) {
    y = app->getHeight() - r - 10;
    app->applyCamSpeed(0, -ySpeed);
    float v = std::abs(ySpeed / 200);
    v = v < 1.0 ? v : 1.0;
    SetSoundVolume(app->collisionSound, v);
    PlaySound(app->collisionSound);
    ySpeed *= -0.95;
  }

  if (std::abs(ySpeed) < 0.1)
    ySpeed = 0;
  if (std::abs(xSpeed) < 0.1)
    xSpeed = 0;
}
