#include "Cell.h"

Cell::Cell()
    : m_Rectangle(0, 0, CELL_SIZE, CELL_SIZE), m_X(0), m_Y(0)
{
}

Cell::Cell(int x, int y)
    : m_Rectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE), m_X(x), m_Y(y)
{
}

Cell::~Cell() = default;
