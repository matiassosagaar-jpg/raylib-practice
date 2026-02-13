#pragma once
#include "Character.hpp"

class Player : public Character {
private:
    int agility = 3, strenght = 3, intelect = 3, level = 1;
    void Walk();
public:
    Player();
    void Update() override;
};