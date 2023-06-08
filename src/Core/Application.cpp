#include "Application.h"
#include "../Core.h"

Application* Application::s_Instance = nullptr;

Application::Application()
{
    ASSERT(!s_Instance, "Application already exists!");
    s_Instance = this;

    InitSDL();
}

Application::~Application()
{
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
