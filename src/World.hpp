#pragma once
#include <raylib.h>
#include <vector>

class World
{
private:
    std::vector<Rectangle> colliders;

public:
    World();

    const std::vector<Rectangle>& GetColliders() const;
    void Draw() const;
};

// This is just a class that contains a vector of Rectangles, has a Getter for this vector
// and a draw method to draw the rectangles