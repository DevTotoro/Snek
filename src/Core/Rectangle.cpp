#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
{
    m_Rect.x = x;
    m_Rect.y = y;
    m_Rect.w = width;
    m_Rect.h = height;
}

Rectangle::~Rectangle() = default;
