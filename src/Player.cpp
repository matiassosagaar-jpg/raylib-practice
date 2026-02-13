#include "Player.hpp"

Player::Player() : Character::Character() {
}

void Player::Walk() {
    if (IsKeyDown(KEY_D))
        position.x +=3;
    if (IsKeyDown(KEY_A))
        position.x -=3;
    if (IsKeyDown(KEY_W))
        position.y -=3;
    if (IsKeyDown(KEY_S))
        position.y +=3;
}

void Player::Update() {
    this->Walk();
}