#include "raylib.h"
#include <stdio.h>

int main() {
     InitWindow(1000, 500, "Pong");
     SetTargetFPS(20);

     int x = 500;
     int y = 250;
     int dx = 15;
     int dy = 13;
     int p = 0;
     int dp = 0;
     int c = 0;
     int score = 0;
     char text[50];

     while(!WindowShouldClose()) {
          x += dx;
          y += dy;
          p += dp;
          c = y - 50;

          if(IsKeyPressed(KEY_UP)) dp = -10;
          if(IsKeyPressed(KEY_DOWN)) dp = 10;

          if(x > 970) dx *= -1;
          if(y < 10 || y > 490) dy *= -1;

          if(c < 0) c = 0;
          if(c > 400) c = 400;
          if(p < 0) p = 0;
          if(p > 400) p = 400;
          
          if(x < 30) {
               if(y > p - 10 && y < p + 110) {
                    dx *= -1;
                    score++;
               } else {
                    break;
               }
          }

          sprintf(text, "Score: %d", score);
          BeginDrawing();
          ClearBackground(BLACK);
          DrawText(text, 470, 30, 20, LIGHTGRAY);
          DrawCircle(x, y, 10, WHITE);
          DrawRectangle(0, p, 20, 100, WHITE);
          DrawRectangle(980, c, 20, 100, WHITE);
          EndDrawing();
     }

     CloseWindow();
}