#include <raylib.h>
#include "Player.hpp"
int main() {
    InitWindow(800,600,"Pedrito");
    SetTargetFPS(60);
    Player player;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    
}
