#pragma once
#include <array>

enum class TetrominoType {
    I, O, T, S, Z, J, L
};

class Tetromino {
private:
    TetrominoType type;
    std::array<std::array<bool, 4>, 4> shape;
    int x, y;

public:
    Tetromino(TetrominoType type);

    const std::array<std::array<bool, 4>, 4>& getShape() const { return shape; }
    TetrominoType getType() const { return type; }

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    void setPosition(int newX, int newY);

    void rotate();
};
