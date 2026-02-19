#pragma once
#include <raylib.h>
struct Grid {
    static constexpr int Width = 1920, Height = 1080;
    static constexpr int CellSize = 20, Rows = 54, Columns = 96;

    static void Draw();
};
