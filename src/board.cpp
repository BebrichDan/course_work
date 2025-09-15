#include "board.h"
#include "tetromino.h"

Board::Board(int w, int h) : width(w), height(h) {
    grid.resize(height, std::vector<int>(width, 0));
}

bool Board::checkCollision(const Tetromino& piece, int dx, int dy) const {
    auto shape = piece.getShape();
    int x = piece.getX() + dx;
    int y = piece.getY() + dy;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j]) {
                int newY = y + i;
                int newX = x + j;
                if (newX < 0 || newX >= width || newY >= height) return true;
                if (newY >= 0 && grid[newY][newX]) return true;
            }
        }
    }
    return false;
}

void Board::placePiece(const Tetromino& piece) {
    auto shape = piece.getShape();
    int x = piece.getX();
    int y = piece.getY();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j]) {
                int newY = y + i;
                int newX = x + j;
                if (newY >= 0 && newY < height && newX >= 0 && newX < width) {
                    grid[newY][newX] = 1;
                }
            }
        }
    }
}

int Board::clearLines() {
    int cleared = 0;
    for (int i = 0; i < height; i++) {
        bool full = true;
        for (int j = 0; j < width; j++) {
            if (!grid[i][j]) {
                full = false;
                break;
            }
        }
        if (full) {
            cleared++;
            for (int k = i; k > 0; k--) {
                grid[k] = grid[k - 1];
            }
            grid[0] = std::vector<int>(width, 0);
        }
    }
    return cleared;
}

void Board::reset() {
    grid.assign(height, std::vector<int>(width, 0));
}

void Board::clearGrid() {
    reset(); 
}