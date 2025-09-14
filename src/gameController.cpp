#include "gameController.h"
#include <iostream>

GameController::GameController(Board& b, TetrominoFactory& f, Progress& p)
    : board(b), factory(f), progress(p), currentPiece(factory.createRandomTetromino()) {}

void GameController::spawnNewPiece() {
    currentPiece = factory.createRandomTetromino();
    currentPiece.setX(board.getWidth() / 2 - 2);
    currentPiece.setY(0);

    if (board.checkCollision(currentPiece, 0, 0)) {
        progress.setGameOver(true);
    }
}

void GameController::update() {
    if (progress.isGameOver()) return;

    currentPiece.moveDown();

    if (board.checkCollision(currentPiece, 0, 0)) {
        currentPiece.moveUp();
        board.placePiece(currentPiece);

        int cleared = board.clearLines();
        if (cleared > 0) {
            progress.addScore(cleared);
        }
        spawnNewPiece();
    }
}

void GameController::moveLeft() {
    currentPiece.moveLeft();
    if (board.checkCollision(currentPiece, 0, 0)) {
        currentPiece.moveRight();
    }
}

void GameController::moveRight() {
    currentPiece.moveRight();
    if (board.checkCollision(currentPiece, 0, 0)) {
        currentPiece.moveLeft();
    }
}

void GameController::rotate() {
    currentPiece.rotate();
    if (board.checkCollision(currentPiece, 0, 0)) {
        currentPiece.rotate();
        currentPiece.rotate();
        currentPiece.rotate();
    }
}

void GameController::drop() {
    while (!board.checkCollision(currentPiece, 0, 0)) {
        currentPiece.moveDown();
    }
    currentPiece.moveUp();
    board.placePiece(currentPiece);

    int cleared = board.clearLines();
    if (cleared > 0) progress.addScore(cleared);
    spawnNewPiece();
}