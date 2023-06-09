#include "Application.h"
#include "../Core.h"

Application* Application::s_Instance = nullptr;

// ==================== PUBLIC ==================== //

Application::Application()
{
    ASSERT(!s_Instance, "Application already exists!");
    s_Instance = this;

    InitSDL();

    m_Window = std::make_unique<Window>(
        "Snek",
        Game::GAME_WIDTH,
        Game::GAME_HEIGHT
    );

    m_Renderer = std::make_shared<Renderer>(*m_Window);

    m_Game = std::make_unique<Game>(std::shared_ptr<Renderer>(m_Renderer));
}

Application::~Application()
{
    m_Game = nullptr;

    m_Renderer.reset();

    m_Window = nullptr;

    QuitSDL();
}

void Application::Run()
{
    Update();
    Render();

    SDL_Delay(3000);
}

// ==================== PRIVATE ==================== //

void Application::InitSDL()
{
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    ASSERT(sdlResult == 0, SDL_GetError());

    CORE_LOG("SDL Initialized");
}

void Application::QuitSDL()
{
    SDL_Quit();
    CORE_LOG("SDL Quit");
}

void Application::Update()
{
    m_Game->Update();
}

void Application::Render()
{
    m_Renderer->DrawBackground();

    m_Game->Draw();

    m_Renderer->Render();
}
