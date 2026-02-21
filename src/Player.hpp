#pragma once
#include "Character.hpp"

class Player : public Character
{
private:
    int agility = 3;
    int strength = 3;
    int intellect = 3;
    int level = 1;

    void HandleInput();
    void ApplyMovement(float dt);

public:
    Player(float x, float y);
    void Update(float dt) override;
};