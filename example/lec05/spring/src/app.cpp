#include "app.h"
#include "raylib.h"
#include <algorithm>
#include <iostream>

App::App(int width, int height, const std::string &title)
    : ball({width / 2.0f, height / 2.0f}, {0.0f, 0.0f}, 20, RED, 4.0f)
{
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);

    this->width = width;
    this->height = height;
}

void App::run()
{
    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();

        BeginDrawing();
        PollInputEvents();

        draw(delta);

        EndDrawing();
    }

    CloseWindow();
}

void App::setup()
{
}

void App::draw(float delta)
{
    ClearBackground(RAYWHITE);
    ball.update(delta);
    ball.draw();

    Vector2 mouse = GetMousePosition();
    DrawLineV(ball.getPosition(), mouse, BLACK);
}
