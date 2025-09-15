#ifndef TETROMINO_FACTORY_H
#define TETROMINO_FACTORY_H

#include <random>

#include "tetromino.h"

class TetrominoFactory {
 public:
  Tetromino createRandomTetromino();
};

#endif