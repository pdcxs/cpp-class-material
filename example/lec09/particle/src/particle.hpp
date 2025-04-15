#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include "app.hpp"
#include "circle.hpp"
#include "raylib.h"
#include "rect.hpp"
#include "shape.hpp"
#include <algorithm>
#include <memory>
#include <vector>

class Particle {
public:
  explicit Particle(App *app) {
    this->app = app;
    pos = {(float)app->getWidth() / 2, (float)app->getHeight()};
  }

  void addParticle() {
    int choice = GetRandomValue(0, 1);
    if (choice == 0) {
      particles.push_back(std::make_unique<Circle>(
          pos, getInitVel(), GetRandomValue(10, 20), RED));
    } else {
      particles.push_back(std::make_unique<Rect>(
          pos, getInitVel(), GetRandomValue(15, 30), BROWN));
    }
  }

  void draw() const {
    for (auto &p : particles) {
      p->draw();
    }
  }

  void update(float delta) {
    int w = app->getWidth();
    int h = app->getHeight();
    // std::cout << pos.x << ", " << pos.y << std::endl;
    auto it = std::remove_if(
        particles.begin(), particles.end(),
        [w, h](std::unique_ptr<Shape> &p) { return p->isDead(w, h); });
    particles.erase(it, particles.end());
    for (auto &p : particles) {
      p->applyForce({0, 200});
      p->update(delta);
    }
  }

private:
  const App *app;
  std::vector<std::unique_ptr<Shape>> particles;
  Vector2 pos;

  Vector2 getInitVel() const {
    float x = (float)GetRandomValue(-50, 50);
    float y = (float)GetRandomValue(-600, -300);
    return {x, y};
  }
};

#endif // !__PARTICLE_H__
