#include "Game.h"

Color Game::s_BoardColor = Color(30, 30, 30);

// ==================== PUBLIC ==================== //

Game::Game(std::shared_ptr<Renderer> renderer)
    : m_Renderer(renderer)
{
    // Setup board
    m_Board.reserve(BOARD_HEIGHT);
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        CellRow row(BOARD_WIDTH);
        m_Board.push_back(row);

        for (int j = 0; j < BOARD_WIDTH; j++)
            m_Board[i][j] = std::make_shared<Cell>(j, i);
    }

    ResetBoard();
}

Game::~Game()
{
    m_Board.clear();

    m_Renderer.reset();
}

void Game::Draw() const
{
    for (const auto& row : m_Board)
        for (const auto& cell : row)
            m_Renderer->DrawRectangle(cell->GetRectangle());
}

// ==================== PRIVATE ==================== //

void Game::ResetBoard()
{
    for (const auto& row : m_Board)
        for (const auto& cell : row)
        {
            cell->SetFillColor(s_BoardColor);
            cell->SetBorderColor(s_BoardColor);
        }
}
