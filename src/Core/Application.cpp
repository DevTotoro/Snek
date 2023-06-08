#include "Application.h"
#include "../Core.h"

Application* Application::s_Instance = nullptr;

Application::Application()
{
    ASSERT(!s_Instance, "Application already exists!");
    s_Instance = this;

    InitSDL();

    m_Window = std::make_unique<Window>("Snek", GRID_WIDTH, GRID_HEIGHT);

    m_Renderer = std::make_unique<Renderer>(*m_Window);
}

Application::~Application()
{
    m_Renderer = nullptr;

    m_Window = nullptr;

    QuitSDL();
}

void Application::Run()
{
    SDL_Delay(3000);
}

void Application::InitSDL()
{
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    ASSERT(sdlResult == 0, SDL_GetError());

    LOG("SDL Initialized");
}

void Application::QuitSDL()
{
    SDL_Quit();
    LOG("SDL Quit");
}
