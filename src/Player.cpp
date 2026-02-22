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

void Player::ResolveCollisions(float dt, const std::vector<Rectangle>& worldColliders)
{
    hitBox.x += velocity.x * moveSpeed * dt;  //movement application

    for (const auto& col : worldColliders) // for each collider in worldcolliders
    {
        if (CheckCollisionRecs(hitBox, col)) // If we have a collision between player's hitbox and the collider
        {
            if (velocity.x > 0) // if we're moving to the right
            {
                hitBox.x = col.x - hitBox.width; // then we'll match the right side of the hitbox to the left side of the collider hitbox
            }
            else if (velocity.x < 0) // if moving to the left
            {
                hitBox.x = col.x + col.width; // then we'll math the left side of the hitbox to the right side of the collider
            }
        }
    }

    // And the same applies to the y movement
    hitBox.y += velocity.y * moveSpeed * dt;

    for (const auto& col : worldColliders) // for each collider
    {
        if (CheckCollisionRecs(hitBox, col)) // if it collides with hitbox
        {
            if (velocity.y > 0) // collision from the top
            {
                hitBox.y = col.y - hitBox.height; // sets hitbox just on top of the collider
            }
            else if (velocity.y < 0)  // collision from the bottom
            {
                hitBox.y = col.y + col.height; // sets hitbox's top on collider's bottom
            }
        }
    }
}

void Player::Update(float dt)
{
    HandleInput();
}
