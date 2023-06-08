#pragma once
#include <SDL.h>
#include "Window.h"
#include "Color.h"

class Renderer
{
public:
    Renderer(Window& window);
    ~Renderer();

    void DrawBackground();

    void Render();

public:
    Color backgroundColor;

private:
    SDL_Renderer* m_Renderer = nullptr;
};
