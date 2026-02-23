#pragma once
#include "Character.hpp"
#include <vector>
class Player : public Character
{
public:
    // ---- Types ----
    enum class State
    {
        Idle,
        Move,
        Attack,
        Dash,
        Hit,
        Dead
    };

public:
    // ---- Constructor ----
    Player(float x, float y);

    // ---- Public Interface ----
    void Update(float dt) override;
    void ResolveCollisions(float dt, const std::vector<Rectangle>& worldColliders);

    State GetState() const;

private:
    // ---- Internal Logic ----
    void HandleInput();

    void UpdateIdle(float dt);
    void UpdateMove(float dt);

private:
    // ---- Stats ----
    int agility = 3;
    int strength = 3;
    int intellect = 3;
    int level = 1;

    // ---- State ----
    State currentState = State::Idle;
};