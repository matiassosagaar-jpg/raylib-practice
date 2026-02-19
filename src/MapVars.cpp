#include "MapVars.hpp"

void Grid::Draw() {
    for (int r {1}; r <= Rows; r++) //Rows
        DrawLine(0, r*CellSize, Width, r*CellSize, DARKGRAY);
    for (int c {1}; c <= Columns; c++) //Columns
        DrawLine(c*CellSize, 0, c*CellSize, Height, DARKGRAY);
}