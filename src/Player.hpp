#pragma once
#include "Character.hpp"

class Player : public Character {
private:
    int agility, strenght, intelect;
public:
    Player();
    void Update() override;
};