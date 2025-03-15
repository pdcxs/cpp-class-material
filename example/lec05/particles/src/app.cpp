#include "app.h"
#include "raylib.h"
#include <algorithm>
#include <iostream>

App::App(int width, int height, const std::string &title)
{
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);

    this->width = width;
    this->height = height;

    removeDead = true;
    std::cout << std::boolalpha;
}

void App::run()
{
    while (!WindowShouldClose())
    {
        float delta = GetFrameTime();
        
        BeginDrawing();
        PollInputEvents();

        DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, RED);
        DrawText(TextFormat("Particles: %i", particles.size()), 10, 30, 20, RED);

        draw(delta);

        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            removeDead = !removeDead;
            std::cout << "removeDead: " << removeDead << std::endl;
        }
    }

    CloseWindow();
}

void App::setup()
{
}

void App::draw(float delta)
{
    ClearBackground(RAYWHITE);

    for (int i = 0; i < 5; i++)
        addParticle();

    if (removeDead)
        particles.erase(
            std::remove_if(
                particles.begin(), particles.end(),
                [](const Particle &p)
                { return p.isDead(); }),
            particles.end());

    for (auto &particle : particles)
    {
        particle.update(delta);
        particle.draw();
    }
}

void App::addParticle()
{
    float startX = width / 2;
    float startY = height + 10;

    float xSpeed = GetRandomValue(-100, 100);
    float ySpeed = GetRandomValue(-600, -500);

    Color randColor{
        (unsigned char)GetRandomValue(0, 255),
        (unsigned char)GetRandomValue(0, 255),
        (unsigned char)GetRandomValue(0, 255), 255};

    particles.push_back(
        {{startX, startY}, {xSpeed, ySpeed}, randColor});
}