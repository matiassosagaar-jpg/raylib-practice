#pragma once
#include <raylib.h>
#include "Player.hpp"

class Game {
private:
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