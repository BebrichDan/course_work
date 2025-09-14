#include "gameController.h"
#include <iostream>

GameController::GameController(Board& b, TetrominoFactory& f, Progress& p)
    : board(b), factory(f), progress(p), currentPiece(factory.createRandomTetromino()) {}

void GameController::spawnNewPiece() {
    currentPiece = factory.createRandomTetromino();
    currentPiece.setX(board.getWidth() / 2 - 2);
    currentPiece.setY(0);

    // Проверка, не заспавнились ли мы на занятых клетках
    if (board.checkCollision(currentPiece, 0, 0)) {
        progress.setGameOver(true);
        std::cout << "GAME OVER!" << std::endl;
    }
}

void GameController::update() {
    if (progress.isGameOver()) return;

    // Двигаем фигуру вниз
    currentPiece.moveDown();

    // Проверяем, не врезались ли мы
    if (board.checkCollision(currentPiece, 0, 0)) {
        // Возвращаем фигуру наверх на 1 клетку
        currentPiece.moveUp();
        // Фиксируем фигуру
        board.placePiece(currentPiece);
        // Удаляем линии
        int cleared = board.clearLines();
        if (cleared > 0) {
            progress.addScore(cleared);
        }
        // Спавним новую
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
        // Откат вращения (можно сделать rotateBack)
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