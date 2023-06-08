#pragma once
#include <SDL.h>
#include "Window.h"
#include "Color.h"
#include "Rectangle.h"

class Renderer
{
public:
    Renderer(Window& window);
    ~Renderer();

    void DrawBackground();
    void DrawRectangle(Rectangle& rectangle);

    void Render();

public:
    Color backgroundColor;

private:
    SDL_Renderer* m_Renderer = nullptr;
};
