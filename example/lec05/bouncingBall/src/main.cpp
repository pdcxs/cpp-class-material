#include "app.h"
#include "ball.h"
#include <raylib.h>

int main() {
  App app{400, 400, "Bouncing Ball"};
  Ball ball(&app, 50, 70, 20, RED);
  app.setActions(
      []() {
        // do nothing
      },
      [&](float delta) {
        ClearBackground(WHITE);
        float lineThickness = 2.0f;
        DrawLineEx({10.0f, 10.0f}, {10.0f, 390.0f}, lineThickness, BLACK);
        DrawLineEx({10.0f, 390.0f}, {390.0f, 390.0f}, lineThickness, BLACK);
        DrawLineEx({390.0f, 390.0f}, {390.0f, 10.0f}, lineThickness, BLACK);
        DrawLineEx({390.0f, 10.0f}, {10.0f, 10.0f}, lineThickness, BLACK);

        std::string text = "BOUNCING BALL!";
        int fontSize = 40;

        DrawText(text.c_str(), 40, 40, fontSize, BLUE);

        for (int i = -50; i <= app.getHeight() + 50; i += 50) {
          DrawLine(-50, i, app.getWidth() + 50, i, GRAY);
        }
        for (int i = -50; i <= app.getWidth() + 50; i += 50) {
          DrawLine(i, -50, i, app.getHeight() + 50, GRAY);
        }

        ball.update(delta);
        ball.draw();
      });
  app.run();
  return 0;
}
