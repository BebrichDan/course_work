#ifndef RENDERER_SFML_H
#define RENDERER_SFML_H

#include <SFML/Graphics.hpp>
#include "board.h"
#include "tetromino.h"
#include "player.h"
#include "progress.h"
#include "scoreManager.h"

class RendererSFML {
public:
    RendererSFML(Board& b);

    // Основной рендер во время игры
    void render(sf::RenderWindow& window, const Tetromino& piece, const Player& player, const Progress& progress);

    // Экран проигрыша
    void renderGameOver(sf::RenderWindow& window, const Progress& progress, const ScoreManager& scoreManager);

private:
    Board& board;
    sf::Font font;
};

#endif // RENDERER_SFML_H
