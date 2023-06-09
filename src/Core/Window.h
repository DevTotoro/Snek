#pragma once
#include <SDL.h>
#include <string>

class Window
{
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    inline SDL_Window& GetWindow() const { return *m_Window; }

private:
    SDL_Window* m_Window = nullptr;
};
