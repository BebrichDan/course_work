#include "tetrominoFactory.h"

Tetromino TetrominoFactory::createRandomTetromino() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 6);

    return Tetromino(static_cast<TetrominoType>(dist(gen)));
}