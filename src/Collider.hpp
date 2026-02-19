#pragma once
#include <vector>
#include <raylib.h>
struct Collider {
    Rectangle bounds;
    bool IsBlocking; // to block movement
    bool isTrigger; // for special zones
};