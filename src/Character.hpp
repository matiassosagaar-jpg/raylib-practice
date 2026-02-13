#pragma once
#include <raylib.h>

class Character
{
private:
    int hp, mp, stam; // Stands for health-points, mana-points and stamina
    Vector2 position;
    Rectangle hitBox;
    
public:
    virtual void Update();  // This is a method that will contain all the behaviour of a Character Object
    Character(int hp = 100, int mp = 50, int stam = 25);
    virtual ~Character() = default;
};
