#include <raylib.h>
#include "Player.hpp"
#include "MapVars.hpp"
#include "Game.hpp"
int main() {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(Grid::Width, Grid::Height,"Pedrito");
    SetTargetFPS(60);
    Game game;
    while (!WindowShouldClose()) {
        game.Update();
        game.Draw();
    }
    CloseWindow();    
}
