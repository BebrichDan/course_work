#ifndef RENDERER_SFML_H
#define RENDERER_SFML_H

#include <SFML/Graphics.hpp>
#include "board.h"
#include "tetromino.h"
#include "progress.h"
#include "player.h"

class RendererSFML {
private:
    Board& board;
    sf::RenderWindow window;
    const int blockSize = 30;

public:
    RendererSFML(Board& b);

    bool isOpen() const;
    void processEvents(bool &running, bool &moveLeft, bool &moveRight, bool &rotate, bool &drop);
    void render(const Tetromino& piece, const Player& player, const Progress& progress);
};

#endif
