#pragma once
#include <memory>
#include <SDL.h>
#include "Window.h"
#include "Renderer.h"
#include "../Game/Game.h"

class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    static Application* s_Instance;

    static bool s_Running;

    std::unique_ptr<Window> m_Window = nullptr;
    std::shared_ptr<Renderer> m_Renderer = nullptr;

    std::unique_ptr<Game> m_Game = nullptr;

private:
    static void InitSDL();
    static void QuitSDL();

    void PollEvents();
    void Update();
    void Render();
};
