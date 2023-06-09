#include "Game.h"

Game::Game(std::shared_ptr<Renderer> renderer)
    : m_Renderer(renderer)
{
}

Game::~Game()
{
    m_Renderer.reset();
}
