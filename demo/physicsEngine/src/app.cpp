#include "app.h"
#include "dot.h"
#include <algorithm>
#include <box2d/box2d.h>
#include <box2d/types.h>
#include <memory>
#include <raylib.h>
#include <sstream>

App::App(int width, int height, const std::string &title) {
  b2WorldDef worldDef = b2DefaultWorldDef();
  worldDef.gravity = {0.0f, 200.0f};
  worldId = b2CreateWorld(&worldDef);

  this->width = width;
  this->height = height;

  addWalls();

  InitWindow(width, height, title.c_str());
  SetTargetFPS(60);
}

void App::run() {
  while (!WindowShouldClose()) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      for (int i = 0; i < 3; i++) {
        auto mouse = GetMousePosition();
        particles.push_back(std::make_unique<Dot>(worldId, mouse, 5, SKYBLUE));
      }
    }

    float time = GetFrameTime();
    update(time);

    int fps = GetFPS();

    BeginDrawing();
    ClearBackground(WHITE);
    draw();

    std::ostringstream oss;
    oss << "FPS: " << fps;
    DrawText(oss.str().c_str(), 10, 20, 20, RED);
    oss.str("");
    oss.clear();
    oss << "Particle Num: " << particles.size();
    DrawText(oss.str().c_str(), 10, 50, 20, RED);
    DrawText("Click Left Mouse Button To Add Particles!", 50, 100, 40, BLUE);
    EndDrawing();
  }

  CloseWindow();
}

void App::update(float delta) {
  particles.erase(std::remove_if(particles.begin(), particles.end(),
                                 [this](std::unique_ptr<Particle> &p) {
                                   return p->getPos().y > height + 100;
                                 }),
                  particles.end());
  b2World_Step(worldId, delta, 1);
}

void App::draw() {
  for (auto &p : particles) {
    p->draw();
  }
  for (auto &w : walls) {
    w->draw();
  }
}

void App::addWalls() {
  // ground
  float groundHeight = 10.0f;
  Vector2 groundPos{width / 2.0f, height - groundHeight / 2.0f};
  Vector2 groundSize{(float)width, groundHeight};
  walls.push_back(std::make_unique<Wall>(worldId, groundPos, groundSize, 0.0f));

  // left wall
  float lwallWidth = 10.0f;
  float lwallHeight = 100.0f;
  Vector2 lwallPos{lwallWidth / 2.0f, height - lwallHeight / 2.0f};
  Vector2 lwallSize{lwallWidth, lwallHeight};
  walls.push_back(std::make_unique<Wall>(worldId, lwallPos, lwallSize, 0.0f));

  // right wall
  float rwallWidth = 10.0f;
  float rwallHeight = 100.0f;
  Vector2 rwallPos{width - rwallWidth / 2.0f, height - rwallHeight / 2.0f};
  Vector2 rwallSize{rwallWidth, rwallHeight};
  walls.push_back(std::make_unique<Wall>(worldId, rwallPos, rwallSize, 0.0f));

  // obstacle 1
  Vector2 obs1Pos{700.0f, 300.0f};
  Vector2 obs1Size{300.0f, 10.0f};
  walls.push_back(std::make_unique<Wall>(worldId, obs1Pos, obs1Size, -30.0f));

  // obstacle 2
  Vector2 obs2Pos{300.0f, 700.0f};
  Vector2 obs2Size{300.0f, 10.0f};
  walls.push_back(std::make_unique<Wall>(worldId, obs2Pos, obs2Size, 30.0f));
}
