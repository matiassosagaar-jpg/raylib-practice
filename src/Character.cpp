#include "Character.hpp"

Character::Character(float x, float y, float width, float height)
    : hp{100}, mp{50}, stam{25},
      hitBox{ x, y, width, height },
      velocity{ 0.0f, 0.0f },
      moveSpeed{ 200.0f } // 200 px/seg
{
}

void Character::DrawHitBox() const
{
    DrawRectangleLinesEx(hitBox, 2, WHITE);
}

Vector2 Character::GetPosition() const
{
        return { hitBox.x + hitBox.width / 2,
             hitBox.y + hitBox.height / 2 };
}