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

void Game::Update()
{
    MoveSnake();

    CheckFoodCollision();
    CheckTailCollision();
}

void Game::Draw() const
{
    for (const auto& row : m_Board)
        for (const auto& cell : row)
            m_Renderer->DrawRectangle(cell->GetRectangle());
}

void Game::SetDirection(Direction direction)
{
    if (m_SnakeDirection == Direction::UP && direction == Direction::DOWN)
        return;
    if (m_SnakeDirection == Direction::DOWN && direction == Direction::UP)
        return;
    if (m_SnakeDirection == Direction::LEFT && direction == Direction::RIGHT)
        return;
    if (m_SnakeDirection == Direction::RIGHT && direction == Direction::LEFT)
        return;

    m_SnakeDirection = direction;
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

        // Check collision with snake head
        valid = true;
        if (m_SnakeHead->CheckCollision(x, y))
        {
            valid = false;
            continue;
        }

        // Check collision with snake tail
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

void Game::MoveSnake()
{
    int headX = m_SnakeHead->GetX();
    int headY = m_SnakeHead->GetY();

    // Move tail
    for (int i = m_SnakeTail.size() - 1; i > 0; i--)
    {
        // If it's the last tail cell, reset it
        // Otherwise, move it to the previous cell
        if (i == m_SnakeTail.size() - 1)
        {
            m_SnakeTail[i]->SetFillColor(s_BoardColor);
            m_SnakeTail[i]->SetBorderColor(s_BoardColor);
        }
        else
        {
            m_SnakeTail[i]->SetFillColor(Color::WHITE);
            m_SnakeTail[i]->SetBorderColor(Color::BLACK);
        }

        m_SnakeTail[i] = m_SnakeTail[i - 1];
    }

    m_SnakeTail[0] = m_SnakeHead;
    m_SnakeTail[0]->SetFillColor(Color::WHITE);

    // Move head
    switch (m_SnakeDirection)
    {
    case Direction::UP:
        headY--;
        break;
    case Direction::DOWN:
        headY++;
        break;
    case Direction::LEFT:
        headX--;
        break;
    case Direction::RIGHT:
        headX++;
        break;
    default:
        break;
    }

    // Check wall collision
    if (headY < 0 || headY >= BOARD_HEIGHT || headX < 0 || headX >= BOARD_WIDTH)
    {
        ResetBoard();
        ResetSnake();
        SpawnFood();

        return;
    }

    m_SnakeHead = m_Board[headY][headX];
    m_SnakeHead->SetFillColor(Color::GREEN);
    m_SnakeHead->SetBorderColor(Color::BLACK);
}

void Game::CheckFoodCollision()
{
    if (m_SnakeHead->CheckCollision(*m_Food))
    {
        AddSnakeTail();

        SpawnFood();
    }
}

void Game::CheckTailCollision()
{
    for (const auto& cell : m_SnakeTail)
        if (m_SnakeHead->CheckCollision(*cell))
        {
            ResetBoard();
            ResetSnake();
            SpawnFood();
        }
}

void Game::AddSnakeTail()
{
    // Find direction of the last tail cell
    int tailX = m_SnakeTail[m_SnakeTail.size() - 1]->GetX();
    int tailY = m_SnakeTail[m_SnakeTail.size() - 1]->GetY();

    int prevTailX = m_SnakeTail[m_SnakeTail.size() - 2]->GetX();
    int prevTailY = m_SnakeTail[m_SnakeTail.size() - 2]->GetY();

    Direction tailDirection;

    if (tailX == prevTailX)
    {
        if (tailY > prevTailY)
            tailDirection = Direction::UP;
        else
            tailDirection = Direction::DOWN;
    }
    else
    {
        if (tailX > prevTailX)
            tailDirection = Direction::LEFT;
        else
            tailDirection = Direction::RIGHT;
    }

    CellPtr newTail = nullptr;

    switch (tailDirection)
    {
    case Direction::UP:
        newTail = m_Board[tailY + 1][tailX];
        break;
    case Direction::DOWN:
        newTail = m_Board[tailY - 1][tailX];
        break;
    case Direction::LEFT:
        newTail = m_Board[tailY][tailX + 1];
        break;
    case Direction::RIGHT:
        newTail = m_Board[tailY][tailX - 1];
        break;
    default:
        break;
    }

    m_SnakeTail.push_back(newTail);
    newTail->SetFillColor(Color::WHITE);
    newTail->SetBorderColor(Color::BLACK);
}
