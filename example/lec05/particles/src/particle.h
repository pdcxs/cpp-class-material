#ifndef PARTICLE_H
#define PARTICLE_H

#include "raylib.h"

class Particle
{
public:
    Particle(Vector2 pos, Vector2 vel, Color color);
    void update(float delta);
    void draw() const;
    bool isDead() const;

private:
    Vector2 position;
    Vector2 velocity;
    Color color;
    float radius;
};

#endif