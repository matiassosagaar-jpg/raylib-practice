#include <raylib.h>
#include "Player.hpp"

#include "Game.hpp"
int main() {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(1920, 1080,"Pedrito");
    SetTargetFPS(60);
    Game game;
    while (!WindowShouldClose()) {
        game.Update();
        game.Draw();
    }
    CloseWindow();    
}
