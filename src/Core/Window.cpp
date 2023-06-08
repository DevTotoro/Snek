#include "Window.h"
#include "../Core.h"

Window::Window(const std::string& title, uint32_t width, uint32_t height)
{
    m_Window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN
    );
    ASSERT(m_Window, SDL_GetError());

    std::string message = "Window created: " + title + " (" + std::to_string(width) + " x " + std::to_string(height) + ")";
    LOG(message);
}

Window::~Window()
{
    SDL_DestroyWindow(m_Window);

    LOG("Window destroyed");
}
