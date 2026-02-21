#include <raylib.h>
#include "Player.hpp"

#include "Game.hpp"

int main()
{
    InitWindow(1920, 1080, "Pedrito");
    SetTargetFPS(60);

    Game game;
    game.Init();

    while (!WindowShouldClose())
    {
        game.Update();
        game.Draw();
    }

    CloseWindow();
}