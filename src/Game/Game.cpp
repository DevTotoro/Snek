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

    ResetSnake();

    SpawnFood();
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

void Game::ResetSnake()
{
    m_SnakeHead = m_Board[BOARD_HEIGHT / 2][BOARD_WIDTH / 2];
    m_SnakeHead->SetFillColor(Color::GREEN);
    m_SnakeHead->SetBorderColor(Color::BLACK);

    m_SnakeTail.clear();
    m_SnakeTail.push_back(m_Board[BOARD_HEIGHT / 2][BOARD_WIDTH / 2 - 1]);
    m_SnakeTail.push_back(m_Board[BOARD_HEIGHT / 2][BOARD_WIDTH / 2 - 2]);

    for (const auto& cell : m_SnakeTail)
    {
        cell->SetFillColor(Color::WHITE);
        cell->SetBorderColor(Color::BLACK);
    }
}

void Game::SpawnFood()
{
    int x = 0, y = 0;
    bool valid = false;

    do
    {
        x = rand() % BOARD_WIDTH;
        y = rand() % BOARD_HEIGHT;

        valid = true;
        if (m_SnakeHead->CheckCollision(x, y))
        {
            valid = false;
            continue;
        }

        for (const auto& cell : m_SnakeTail)
            if (cell->CheckCollision(x, y))
            {
                valid = false;
                break;
            }
    } while (!valid);

    m_Food = m_Board[y][x];

    m_Food->SetFillColor(Color::MAGENTA);
    m_Food->SetBorderColor(Color::BLACK);
}
