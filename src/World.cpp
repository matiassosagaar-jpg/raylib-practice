#include "World.hpp"

World::World()
{
    // Add two obstacles in the constructor to have something to collide with
    colliders.push_back({ 200, 200, 300, 50 });
    colliders.push_back({ 600, 100, 50, 400 });
}
//getter
const std::vector<Rectangle>& World::GetColliders() const
{
    return colliders;
}

void World::Draw() const
{ //just draws all the rectangles from collider
    for (const auto& col : colliders)
        DrawRectangleRec(col, DARKGRAY);
}

