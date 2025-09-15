#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "board.h"
#include "progress.h"
#include "tetromino.h"
#include "tetrominoFactory.h"

class GameController {
 private:
  Board& board;
  TetrominoFactory& factory;
  Progress& progress;
  Tetromino currentPiece;

  void spawnNewPiece();

 public:
  GameController(Board& b, TetrominoFactory& f, Progress& p);

  void update();
  void moveLeft();
  void moveRight();
  void rotate();
  void drop();

  const Tetromino& getCurrentPiece() const { return currentPiece; }
};

#endif