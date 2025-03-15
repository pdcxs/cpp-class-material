#include "particle.h"
#include "raylib.h"

Particle::Particle(Vector2 pos, Vector2 vel, Color color)
    : position(pos), velocity(vel), color(color), radius(5)
{
}

void Particle::update(float delta)
{
    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    velocity.y += 420.0f * delta;
}

void Particle::draw() const
{
    DrawCircleV(position, radius, color);
}

bool Particle::isDead() const
{
    return position.y > GetScreenHeight() + 100;
}