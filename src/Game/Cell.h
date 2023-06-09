#pragma once
#include "../Core/Rectangle.h"

class Cell
{
    friend class Game;

private:
    static constexpr int CELL_SIZE = 20;

public:
    Cell();
    Cell(int x, int y);
    ~Cell();

    inline Rectangle& GetRectangle() { return m_Rectangle; }

    inline int GetX() const { return m_X; }
    inline int GetY() const { return m_Y; }

    inline void SetFillColor(const Color& color) { m_Rectangle.fillColor = color; }
    inline void SetBorderColor(const Color& color) { m_Rectangle.borderColor = color; }

    inline bool CheckCollision(int x, int y) const { return x == m_X && y == m_Y; }
    inline bool CheckCollision(const Cell& cell) const { return CheckCollision(cell.m_X, cell.m_Y); }

private:
    Rectangle m_Rectangle;

    int m_X, m_Y;
};
