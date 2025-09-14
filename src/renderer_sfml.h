#ifndef RENDERER_SFML_H
#define RENDERER_SFML_H

#include <SFML/Graphics.hpp>
#include "board.h"
#include "tetromino.h"
#include "player.h"
#include "progress.h"

class RendererSFML {
public:
    RendererSFML(Board& b);
    void render(sf::RenderWindow& window, const Tetromino& piece, const Player& player, const Progress& progress);
    void renderControls(sf::RenderWindow& window); // 👈 Добавим

private:
    Board& board;
    sf::Font font;
};

#endif
