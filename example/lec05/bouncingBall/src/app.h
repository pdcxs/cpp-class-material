#ifndef __MY_RAYLIB_APP_H__
#define __MY_RAYLIB_APP_H__

#include <functional>
#include <raylib.h>
#include <string>

class App {
public:
  App(int width, int height, const std::string &title);
  void setActions(std::function<void()> setup, std::function<void(float)> draw);
  void run();
  int getWidth() const { return width; }
  int getHeight() const { return height; }
  void applyCamSpeed(int sx, int sy);

public:
  Camera2D camera;
  std::string collisionSound;

private:
  const int width;
  const int height;
  float camSx, camSy;
  float camSpring;
  std::function<void()> setup;
  std::function<void(float)> draw;
};

#endif
