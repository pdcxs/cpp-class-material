#include "particle.h"
#include "wall.h"
#include <box2d/box2d.h>
#include <box2d/id.h>
#include <memory>
#include <raylib.h>
#include <string>
#include <vector>

class App {
public:
  App(int width, int height, const std::string &title);
  void run();
  void draw();
  void update(float delta);
  b2WorldId getWorldId() const;

private:
  std::vector<std::unique_ptr<Particle>> particles;
  b2WorldId worldId;
  int width, height;
  std::vector<std::unique_ptr<Wall>> walls;
  void addWalls();
};
