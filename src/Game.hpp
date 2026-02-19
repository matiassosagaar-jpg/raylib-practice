#pragma once
#include <raylib.h>
#include "Player.hpp"

class Game {
private:

public:
    Player player;

    void Draw();
    void Update();
};