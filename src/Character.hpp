#pragma once
#include <raylib.h>

class Character
{
protected:
    int hp, mp, stam;

    Rectangle hitBox;      // Fuente real de posición
    Vector2 velocity;      // Velocidad actual
    float moveSpeed;       // Velocidad máxima (px/seg)

public:
    Character(float x, float y, float width, float height);
    virtual ~Character() = default;

    virtual void Update(float dt) = 0;
    void DrawHitBox() const;

    Vector2 GetPosition() const;
};
