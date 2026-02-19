#include "Character.hpp"

Character::Character()
: hp {100}, mp {50}, stam {25}, hitBox{0, 0, 36, 72} { // Testing position and hitBox, not determined yet
}

void Character::DrawHitBox() {
    DrawRectangleLines(hitBox.x, hitBox.y, hitBox.width, hitBox.height, WHITE);
}