#include "Game.hpp"

void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    player.DrawHitBox();
    EndDrawing();
}

void Game::Update() {
    player.Update();
}