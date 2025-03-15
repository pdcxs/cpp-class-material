#include "app.h"
#include "ball.h"
#include <raylib.h>

int main()
{
  App app{400, 400, "Bouncing Ball"};
  Ball ball(&app, 50, 70, 20, RED);
  app.setActions(
      []()
      {
        // do nothing
      },
      [&](float delta)
      {
        ClearBackground(WHITE);
        DrawLine(10, 10, 10, 390, BLACK);
        DrawLine(10, 390, 390, 390, BLACK);
        DrawLine(390, 390, 390, 10, BLACK);
        DrawLine(390, 10, 10, 10, BLACK);
        ball.update(delta);
        ball.draw();
      });
  app.run();
  return 0;
}
