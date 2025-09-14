#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Tetromino;

class Board {
private:
    int width;
    int height;
    std::vector<std::vector<int>> grid;

public:
    Board(int w = 10, int h = 22);

    bool checkCollision(const Tetromino& piece, int dx, int dy) const;
    void placePiece(const Tetromino& piece);
    int clearLines();
    void reset();

    // Inline-геттеры (НЕ ДЕЛАЕМ ИХ В .cpp!)
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const std::vector<std::vector<int>>& getGrid() const { return grid; }
};

#endif
