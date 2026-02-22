#include "Player.hpp"
#include <raymath.h>

Player::Player(float x, float y)
    : Character(x, y, 36.0f, 72.0f)
{
}

void Player::HandleInput()
{
    velocity = { 0.0f, 0.0f };

    if (IsKeyDown(KEY_D)) velocity.x += 1.0f;
    if (IsKeyDown(KEY_A)) velocity.x -= 1.0f;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0f;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0f;


    if (velocity.x != 0.0f || velocity.y != 0.0f)
    {
        velocity = Vector2Normalize(velocity);
    }
}

void Player::ApplyMovement(float dt)
{
    hitBox.x += velocity.x * moveSpeed * dt;
    hitBox.y += velocity.y * moveSpeed * dt;
}

void Player::Update(float dt)
{
    HandleInput();
}
