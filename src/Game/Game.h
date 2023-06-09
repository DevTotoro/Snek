#pragma once
#include <memory>
#include "../Core/Renderer.h"

class Game
{
public:
    Game(std::shared_ptr<Renderer> renderer);
    ~Game();

public:
    static constexpr int BoardWidth = 40;
    static constexpr int BoardHeight = 30;

private:
    std::shared_ptr<Renderer> m_Renderer = nullptr;
};
