#pragma once
#include <memory>
#include <SDL.h>
#include "Window.h"
#include "Renderer.h"

constexpr int CELL_SIZE = 32;

constexpr int CELL_COUNT_X = 20;
constexpr int CELL_COUNT_Y = 20;

constexpr int GRID_WIDTH = CELL_SIZE * CELL_COUNT_X;
constexpr int GRID_HEIGHT = CELL_SIZE * CELL_COUNT_Y;

class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    static Application* s_Instance;

    std::unique_ptr<Window> m_Window = nullptr;

    std::unique_ptr<Renderer> m_Renderer = nullptr;

private:
    static void InitSDL();
    static void QuitSDL();

    void Render();
};
