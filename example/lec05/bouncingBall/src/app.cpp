#include "app.h"
#include <raylib.h>
#include <string>

using std::string;

App::App(int width, int height, const string &title)
    : width(width), height(height), camera{0}
{
  InitWindow(width, height, title.c_str());
  InitAudioDevice();
  camera.target = {0, 0};
  camera.offset = {0, 0};
  camera.zoom = 1.0f;
  camera.rotation = 0.0f;
  camSx = 0;
  camSy = 0;
  camSpring = 150;
  collisionSound = LoadSound("assets/collision.mp3");
}

void App::run()
{
  setup();

  while (!WindowShouldClose())
  {
    float time = GetFrameTime();
    camSx += time * (-camera.target.x) * camSpring;
    camSy += time * (-camera.target.y) * camSpring;
    camSx *= 0.999;
    camSy *= 0.999;
    camera.target.x += time * camSx;
    camera.target.y += time * camSy;
    if (abs(camSx) < 0.1) {
      camSx = 0;
    }
    if (abs(camSy) < 0.1) {
      camSy = 0;
    }
    BeginDrawing();
    BeginMode2D(camera);
    draw(time);
    EndMode2D();
    EndDrawing();
  }

  CloseWindow();
}

void App::setActions(std::function<void()> setup,
                     std::function<void(float)> draw)
{
  this->setup = setup;
  this->draw = draw;
}

void App::applyCamSpeed(int sx, int sy) {
  camSx += sx;
  camSy += sy;
}