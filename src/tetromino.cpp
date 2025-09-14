#include "tetromino.h"

Tetromino::Tetromino(TetrominoType type) : type(type), x(3), y(0) {
    shape = {};
    switch (type) {
        case TetrominoType::I:
            shape[1][0] = shape[1][1] = shape[1][2] = shape[1][3] = true;
            break;
        case TetrominoType::J:
            shape[0][0] = shape[1][0] = shape[1][1] = shape[1][2] = true;
            break;
        case TetrominoType::L:
            shape[0][2] = shape[1][0] = shape[1][1] = shape[1][2] = true;
            break;
        case TetrominoType::O:
            shape[0][0] = shape[0][1] = shape[1][0] = shape[1][1] = true;
            break;
        case TetrominoType::S:
            shape[0][1] = shape[0][2] = shape[1][0] = shape[1][1] = true;
            break;
        case TetrominoType::T:
            shape[0][1] = shape[1][0] = shape[1][1] = shape[1][2] = true;
            break;
        case TetrominoType::Z:
            shape[0][0] = shape[0][1] = shape[1][1] = shape[1][2] = true;
            break;
    }
}

void Tetromino::rotate() {
    std::array<std::array<bool, 4>, 4> temp = shape;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            shape[j][3 - i] = temp[i][j];
        }
    }
}

void Tetromino::moveLeft() { x--; }
void Tetromino::moveRight() { x++; }
void Tetromino::moveDown() { y++; }
void Tetromino::moveUp() { y--; }
void Tetromino::setPosition(int newX, int newY) { x = newX; y = newY; }
