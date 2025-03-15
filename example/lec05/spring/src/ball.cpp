#include "ball.h"
#include <raymath.h>

Ball::Ball(Vector2 position, Vector2 speed, float radius, Color color, float spring)
{
    this->position = position;
    this->speed = speed;
    this->radius = radius;
    this->color = color;
    this->spring = spring;
    this->acceleration = {0, 0};
    this->friction = 0.99f;
}

void Ball::applyForce(Vector2 force)
{
    acceleration = Vector2Add(acceleration, force);
}

void Ball::draw()
{
    DrawCircleV(position, radius, color);
}

void Ball::update(float delta)
{
    acceleration = {0, 0};

    Vector2 mouse = GetMousePosition();
    Vector2 direction = Vector2Subtract(mouse, position);
    Vector2 force = Vector2Scale(direction, spring);
    applyForce(force);
    applyForce({0, 300.0f});

    speed = Vector2Add(speed, Vector2Scale(acceleration, delta));
    speed = Vector2Scale(speed, friction);
    position = Vector2Add(position, Vector2Scale(speed, delta));
}

Vector2 Ball::getPosition()
{
    return position;
}