#include <raylib.h>
#include "Player.hpp"
#include "MapVars.hpp"
int main() {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(Grid::Width, Grid::Height,"Pedrito");
    SetTargetFPS(60);
    Player player;
    while (!WindowShouldClose()) {
        player.Update();
        BeginDrawing();
        ClearBackground(BLACK);
        Grid::Draw();
        player.DrawHitBox();
        EndDrawing();
    }
    CloseWindow();    
}
