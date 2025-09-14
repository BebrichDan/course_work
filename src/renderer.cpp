#include "renderer.h"
#include <iostream>

Renderer::Renderer(Board& b) : board(b) {}

void Renderer::render(const Tetromino& current, const Player& player, const Progress& progress) {
    const auto& grid = board.getGrid();
    std::vector<std::vector<int>> tempGrid = grid;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (current.getShape()[i][j]) {
                int row = current.getY() + i;
                int col = current.getX() + j;
                if (row >= 0 && row < board.getHeight() && col >= 0 && col < board.getWidth()) {
                    tempGrid[row][col] = 1;
                }
            }
        }
    }

    std::cout << "\033[2J\033[H";

    for (int i = 0; i < board.getHeight(); i++) {
        for (int j = 0; j < board.getWidth(); j++) {
            if (tempGrid[i][j]) {
                std::cout << "[]";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "\nPlayer: " << player.getName()
              << " | Score: " << progress.getScore()
              << " | Level: " << progress.getLevel() << "\n";
}
