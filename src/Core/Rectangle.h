#pragma once
#include <SDL.h>
#include "Color.h"

class Rectangle
{
public:
    Rectangle(int x = 0, int y = 0, int width = 0, int height = 0);
    ~Rectangle();

    inline void SetX(int x) { m_Rect.x = x; }
    inline void SetY(int y) { m_Rect.y = y; }
    inline void SetWidth(int width) { m_Rect.w = width; }
    inline void SetHeight(int height) { m_Rect.h = height; }

    inline int GetX() const { return m_Rect.x; }
    inline int GetY() const { return m_Rect.y; }
    inline int GetWidth() const { return m_Rect.w; }
    inline int GetHeight() const { return m_Rect.h; }

    inline SDL_Rect& GetRect() const { return (SDL_Rect&)m_Rect; }

public:
    Color fillColor;
    Color borderColor;

private:
    SDL_Rect m_Rect;
};
