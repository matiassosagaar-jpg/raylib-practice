#include "Game.hpp"

void Game::Draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    player.DrawHitBox();
    Grid::Draw();
    EndDrawing();
}

void Game::Update() {
    player.Update();
}