#include "Application.h"
#include "../Core.h"

Application* Application::s_Instance = nullptr;

bool Application::s_Running = true;

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
    uint64_t frameStart = 0, frameEnd = 0, deltaTime = 0;

    while (s_Running)
    {
        // Cap FPS
        frameStart = SDL_GetTicks64();
        deltaTime = frameStart - frameEnd;

        if (deltaTime > 1000 / Game::GAME_FPS)
        {
            frameEnd = frameStart;

            PollEvents();
            Update();
            Render();
        }
    }
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

void Application::PollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            s_Running = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                s_Running = false;
                break;
            case SDLK_UP:
                m_Game->SetDirection(Game::Direction::UP);
                break;
            case SDLK_DOWN:
                m_Game->SetDirection(Game::Direction::DOWN);
                break;
            case SDLK_LEFT:
                m_Game->SetDirection(Game::Direction::LEFT);
                break;
            case SDLK_RIGHT:
                m_Game->SetDirection(Game::Direction::RIGHT);
                break;
            }
            break;
        }
    }
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
