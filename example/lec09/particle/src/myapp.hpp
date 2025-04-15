#ifndef __MY_APP_H__
#define __MY_APP_H__

#include "app.hpp"
#include "particle.hpp"

class MyApp : public App {
public:
  MyApp() : App("Particle", 800, 1000, WHITE), particle(this) {}

  void draw() const { particle.draw(); }

  void update(float delta) {
    particle.addParticle();
    particle.update(delta);
  }

private:
  Particle particle;
};

#endif // !__MY_APP_H__
