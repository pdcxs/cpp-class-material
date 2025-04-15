#ifndef __APP_H__
#define __APP_H__

#include "raylib.h"
#include <string>

class App {
public:
  App(const std::string &title, int width, int height, Color background) {
    this->title = title;
    this->width = width;
    this->height = height;
    bgColor = background;
  }

  void run() {
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);
    setup();

    while (!WindowShouldClose()) {
      float delta = GetFrameTime();
      update(delta);
      BeginDrawing();
      ClearBackground(bgColor);
      draw();
      EndDrawing();
    }

    CloseWindow();
  }

  int getWidth() const { return width; }

  int getHeight() const { return height; }

  virtual void setup() {}

  virtual void draw() const {}

  virtual void update(float delta) {}

private:
  std::string title;
  int width, height;
  Color bgColor;
};

#endif // !__APP_H__
