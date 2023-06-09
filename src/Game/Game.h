#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "../Core/Renderer.h"
#include "Cell.h"

class Game
{
private:
    static constexpr int BOARD_WIDTH = 40;
    static constexpr int BOARD_HEIGHT = 40;

public:
    static constexpr int GAME_WIDTH = BOARD_WIDTH * Cell::CELL_SIZE;
    static constexpr int GAME_HEIGHT = BOARD_HEIGHT * Cell::CELL_SIZE;

    static constexpr int GAME_FPS = 10;

public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

public:
    Game(std::shared_ptr<Renderer> renderer);
    ~Game();

    void Update();
    void Draw() const;

    void SetDirection(Direction direction);

private:
    using CellPtr = std::shared_ptr<Cell>;
    using CellRow = std::vector<CellPtr>;

private:
    std::shared_ptr<Renderer> m_Renderer = nullptr;

    std::vector<CellRow> m_Board;
    static Color s_BoardColor;

    CellPtr m_SnakeHead = nullptr;
    std::vector<CellPtr> m_SnakeTail;
    Direction m_SnakeDirection = Direction::RIGHT;

    CellPtr m_Food = nullptr;

private:
    void ResetBoard();
    void ResetSnake();
    void SpawnFood();

    void MoveSnake();
    void CheckFoodCollision();
    void CheckTailCollision();

    void AddSnakeTail();
};
