#include <raylib.h>
#include "Player.hpp"
int main() {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(GetScreenWidth(), GetScreenHeight(),"Pedrito");
    SetTargetFPS(60);
    Player player;
    while (!WindowShouldClose()) {
        player.Update();
        BeginDrawing();
        ClearBackground(BLACK);
        player.DrawHitBox();
        EndDrawing();
    }
    CloseWindow();
    
}
