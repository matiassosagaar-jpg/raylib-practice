#pragma once
#include <raylib.h>
#include "Player.hpp"
#include "MapVars.hpp"
class Game {
private:

public:
    Player player;

    void Draw();
    void Update();
};