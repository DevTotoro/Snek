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

void Renderer::DrawBackground()
{
    SDL_SetRenderDrawColor(
        m_Renderer,
        backgroundColor.r,
        backgroundColor.g,
        backgroundColor.b,
        backgroundColor.a
    );
    SDL_RenderClear(m_Renderer);
}

void Renderer::DrawRectangle(Rectangle& rectangle)
{
    SDL_SetRenderDrawColor(
        m_Renderer,
        rectangle.fillColor.r,
        rectangle.fillColor.g,
        rectangle.fillColor.b,
        rectangle.fillColor.a
    );
    SDL_RenderFillRect(m_Renderer, &rectangle.GetRect());

    SDL_SetRenderDrawColor(
        m_Renderer,
        rectangle.borderColor.r,
        rectangle.borderColor.g,
        rectangle.borderColor.b,
        rectangle.borderColor.a
    );
    SDL_RenderDrawRect(m_Renderer, &rectangle.GetRect());
}

void Renderer::Render()
{
    SDL_RenderPresent(m_Renderer);
}
