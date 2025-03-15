#ifndef APP_H
#define APP_H

#include "ball.h"
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
    Ball ball;
    int width, height;
};

#endif