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
    void ChangeState(State newState);
    bool IsAttackActive() const;
    Rectangle GetAttackHitbox() const;
    State GetState() const;

private:
    // ---- Internal Logic ----
    void HandleInput();
    void UpdateIdle(float dt);
    void UpdateMove(float dt);
    void UpdateAttack(float dt);
    void UpdateAttackHitbox();
private:
    // ---- Stats ----
    int agility = 3;
    int strength = 3;
    int intellect = 3;
    int level = 1;
    // ---- State ----
    State currentState;
    // ---- Attack ----
    float attackDuration;  // Tiempo que dura en realizarse un ataque
    float attackTimer;  // Esto es el tiempo que va a durar el ataque, esto es el estado de ataque
    Rectangle attackHitbox;
    bool attackActive;
};