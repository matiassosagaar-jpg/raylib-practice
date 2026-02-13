#include "Character.hpp"

Character::Character()
: hp {100}, mp {50}, stam {25},
position {0,0},  velocity {1}, hitBox{position.x, position.y, 36, 72} { // Testing position and hitBox, not determined yet
}

void Character::DrawHitBox() {
    DrawRectangleLines(position.x, position.y, hitBox.width, hitBox.height, WHITE);
}