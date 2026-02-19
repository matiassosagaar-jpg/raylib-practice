#include "Player.hpp"

Player::Player() : Character::Character() {
}

void Player::Walk() {
    if (IsKeyDown(KEY_D))
        hitBox.x +=3;
    if (IsKeyDown(KEY_A))
        hitBox.x -=3;
    if (IsKeyDown(KEY_W))
        hitBox.y -=3;
    if (IsKeyDown(KEY_S))
        hitBox.y +=3;
}

void Player::Update() {
    this->Walk();
}