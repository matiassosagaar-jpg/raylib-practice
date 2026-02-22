#include "Game.hpp"
#include <raymath.h>
Game::Game()
    : player(400.0f, 300.0f), deltaTime(0.0f)
{
}

void Game::Init()
{
    camera.target = player.GetPosition();
    camera.offset = { 1920.0f / 2.0f, 1080.0f / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void Game::Update()
{
    deltaTime = GetFrameTime();

    player.Update(deltaTime);
    UpdateCamera();
}

void Game::UpdateCamera()
{
    camera.target = Vector2Lerp(
    camera.target,
    player.GetPosition(),
    3.0f * deltaTime
);
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode2D(camera);
    DrawRectangle(0, 0, 100, 100, RED);
    player.DrawHitBox();

    EndMode2D();

    EndDrawing();
}

