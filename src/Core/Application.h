#pragma once
#include <memory>
#include <SDL.h>

class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    static Application* s_Instance;

private:
    static void InitSDL();
    static void QuitSDL();
};
