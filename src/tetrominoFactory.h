#ifndef TETROMINO_FACTORY_H
#define TETROMINO_FACTORY_H

#include "tetromino.h"
#include <random>

class TetrominoFactory {
public:
    Tetromino createRandomTetromino();
};

#endif
