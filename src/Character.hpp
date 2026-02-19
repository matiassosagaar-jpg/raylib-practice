#pragma once
#include <raylib.h>

class Character
{
protected:
    int hp, mp, stam; // Stands for health-points, mana-points and stamina
    float velocity;
    Rectangle hitBox;
    
public:
    //virtual void Update();  // This is a method that will contain all the behaviour of a Character Object
    void DrawHitBox();
    virtual void Update() = 0;
    Character();
    ~Character() = default;
};
