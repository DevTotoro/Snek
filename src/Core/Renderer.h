#pragma once
#include <SDL.h>
#include "Window.h"

class Renderer
{
public:
    Renderer(Window& window);
    ~Renderer();

private:
    SDL_Renderer* m_Renderer = nullptr;
};
