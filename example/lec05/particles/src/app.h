#ifndef APP_H
#define APP_H

#include "particle.h"
#include <vector>
#include <string>

class App
{
public:
    App(int width, int height, const std::string& title);

    void setup();
    void draw(float delta);
    void run();

private:
    std::vector<Particle> particles;
    int width, height;
    bool removeDead;

    void addParticle();
};

#endif