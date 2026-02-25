#include "Player.hpp"
#include <raymath.h>

Player::Player(float x, float y)
    : Character(x, y, 36.0f, 72.0f), currentState {State::Idle},
    attackDuration {0.4f}, attackTimer {0.0f}, attackActive {false}
{
}

void Player::HandleInput()
{
    velocity = { 0.0f, 0.0f };

    if (IsKeyDown(KEY_D)) velocity.x += 1.0f;
    if (IsKeyDown(KEY_A)) velocity.x -= 1.0f;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0f;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0f;


    if (velocity.x != 0.0f || velocity.y != 0.0f)
    {
        velocity = Vector2Normalize(velocity);
    }
}

void Player::ResolveCollisions(float dt, const std::vector<Rectangle>& worldColliders)
{
    hitBox.x += velocity.x * moveSpeed * dt;  //movement application

    for (const auto& col : worldColliders) // for each collider in worldcolliders
    {
        if (CheckCollisionRecs(hitBox, col)) // If we have a collision between player's hitbox and the collider
        {
            if (velocity.x > 0) // if we're moving to the right
            {
                hitBox.x = col.x - hitBox.width; // then we'll match the right side of the hitbox to the left side of the collider hitbox
            }
            else if (velocity.x < 0) // if moving to the left
            {
                hitBox.x = col.x + col.width; // then we'll math the left side of the hitbox to the right side of the collider
            }
        }
    }

    // And the same applies to the y movement
    hitBox.y += velocity.y * moveSpeed * dt;

    for (const auto& col : worldColliders) // for each collider
    {
        if (CheckCollisionRecs(hitBox, col)) // if it collides with hitbox
        {
            if (velocity.y > 0) // collision from the top
            {
                hitBox.y = col.y - hitBox.height; // sets hitbox just on top of the collider
            }
            else if (velocity.y < 0)  // collision from the bottom
            {
                hitBox.y = col.y + col.height; // sets hitbox's top on collider's bottom
            }
        }
    }
}

// ------ Getters -------
Player::State Player::GetState() const 
{
    return currentState;
}

bool Player::IsAttackActive() const
{
    return attackActive;
}

Rectangle Player::GetAttackHitbox() const
{
    return attackHitbox;
}
// ------------------------
void Player::ChangeState(State newState) 
{
    if (currentState == newState) // Evitando transiciones redundantes
        return;

    currentState = newState;

    switch (newState)
    {
    case State::Attack:
        attackTimer = attackDuration; // Si cambiamos al estado Attack, activaremos el cd de AttackTimer
        velocity = {0.0f, 0.0f};      // La idea es que cuando Attack timer sea 0, se pueda usar devuelta el ataque
        break;                       
    
    default:
        break;
    }
}
void Player::UpdateIdle(float dt)
{  // Basicamente maneja el input y luego se fija si el el vector de velocidad no es 0,0 para setear el miembro "currentState"
    HandleInput();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {   // El keybind para el ataque básico va a ser el boton izquierdo del mouse
        ChangeState(State::Attack);
        return;
    }
    if (velocity.x != 0 || velocity.y != 0)
    {
        ChangeState(State::Move);
    }
}

void Player::UpdateMove(float dt)
{  // Maneja input - si el personaje esta quieto, setea currentState a Idle
    HandleInput();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {   // El keybind para el ataque básico va a ser el boton izquierdo del mouse
        ChangeState(State::Attack);
        return;
    }
    if (velocity.x == 0 && velocity.y == 0)
    {
        ChangeState(State::Idle);
    }
}

void Player::UpdateAttack(float dt)
{
    attackTimer -= dt;  
    
    float elapsed = attackDuration - attackTimer; // Tiempo transcurrido desde que se inició la acción de atacar

    if (elapsed >= 0.1f && elapsed <= 0.25f) // La hitbox del ataque durara entre el segundo 0.1 y 0.25 desde que cambió el estado
    {
        attackActive = true;
        UpdateAttackHitbox(); 
    }
    else
    {
        attackActive = false;
    }
    if (attackTimer <= 0.0f)    // si el attack timer es igual o menor a cero quiere decir que ya terminó
    {
        attackActive = false;  // seteando attackActive a falso y volviendo a estado inactivo.
        ChangeState(State::Idle);
    }
}

void Player::UpdateAttackHitbox()
{
    float range = 40.0f;

    attackHitbox = {
        hitBox.x + hitBox.width, // Hitbox xPos will be on Player's right side
        hitBox.y,   // It's yPos will be the same as Player's
        range,      // The range of the attack will be the width of the rectangle
        hitBox.height   //  It'll have the same amplitude as the player's height
    };
}
void Player::Update(float dt)
{
    switch (currentState)
    {
        case State::Idle:
            UpdateIdle(dt);
            break;

        case State::Move:
            UpdateMove(dt);
            break;

        case State::Attack:
            UpdateAttack(dt);
            break;

        default:
            break;
    }
}
