#pragma once
#include <raylib.h>
#include "Player.hpp"
#include "World.hpp"
class Game {
private:
    World world;
    Player player;
    Camera2D camera;

    float deltaTime;

    void UpdateCamera();

public:
    Game();

    void Init();
    void Update();
    void Draw();
};