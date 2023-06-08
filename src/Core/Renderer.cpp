#include "Renderer.h"
#include "../Core.h"

Renderer::Renderer(Window& window)
{
    // Check if the window already has a renderer
    bool hasRenderer = SDL_GetRenderer(&window.GetWindow()) != nullptr;
    ASSERT(!hasRenderer, "Window already has a renderer!");

    m_Renderer = SDL_CreateRenderer(&window.GetWindow(), -1, SDL_RENDERER_ACCELERATED);
    ASSERT(m_Renderer, SDL_GetError());

    LOG("Renderer created");
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_Renderer);
    LOG("Renderer destroyed");
}
