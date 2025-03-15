#ifndef __BALL_H__
#define __BALL_H__

#include <raylib.h>

class Ball {
public:
    Ball(Vector2 position, Vector2 speed, float radius, Color color, float spring);
    void update(float delta);
    void draw();
    void applyForce(Vector2 force);
    Vector2 getPosition();

private:
    Vector2 position;
    Vector2 speed;
    Vector2 acceleration;
    float radius;
    Color color;
    float spring;
    float friction;
};

#endif