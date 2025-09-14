#include "renderer_sfml.h"
#include <iostream>

RendererSFML::RendererSFML(Board& b) : board(b) {
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Не удалось загрузить шрифт!" << std::endl;
    }
}

void RendererSFML::render(sf::RenderWindow& window, const Tetromino& piece, const Player& player, const Progress& progress) {
    window.clear(sf::Color::Black);

    const int tileSize = 30;
    const int boardWidthPx = board.getWidth() * tileSize;
    const int boardHeightPx = board.getHeight() * tileSize;

    // Центрируем игровое поле
    const int offsetX = 50;
    const int offsetY = 50;

    // 🔹 Рисуем фон поля
    sf::RectangleShape background(sf::Vector2f(boardWidthPx, boardHeightPx));
    background.setPosition(offsetX, offsetY);
    background.setFillColor(sf::Color(30, 30, 30));
    background.setOutlineThickness(2);
    background.setOutlineColor(sf::Color::White);
    window.draw(background);

    // 🔹 Рисуем клетки из grid
    const auto& grid = board.getGrid();
    for (int y = 0; y < board.getHeight(); y++) {
        for (int x = 0; x < board.getWidth(); x++) {
            if (grid[y][x]) {
                sf::RectangleShape cell(sf::Vector2f(tileSize - 1, tileSize - 1));
                cell.setPosition(offsetX + x * tileSize, offsetY + y * tileSize);
                cell.setFillColor(sf::Color::Green);
                window.draw(cell);
            }
        }
    }

    // 🔹 Рисуем текущую фигуру
    auto shape = piece.getShape();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j]) {
                sf::RectangleShape cell(sf::Vector2f(tileSize - 1, tileSize - 1));
                cell.setPosition(offsetX + (piece.getX() + j) * tileSize, offsetY + (piece.getY() + i) * tileSize);
                cell.setFillColor(sf::Color::Red);
                window.draw(cell);
            }
        }
    }

    // 🔹 Выводим текст: очки и уровень
    sf::Text stats;
    stats.setFont(font);
    stats.setCharacterSize(20);
    stats.setFillColor(sf::Color::White);
    stats.setString("Score: " + std::to_string(progress.getScore()) +
                    "\nLevel: " + std::to_string(progress.getLevel()) +
                    "\nPlayer: " + player.getName());
    stats.setPosition(offsetX + boardWidthPx + 20, offsetY);
    window.draw(stats);

    // 🔹 Подсказки
    sf::Text controls;
    controls.setFont(font);
    controls.setCharacterSize(18);
    controls.setFillColor(sf::Color::Yellow);
    controls.setString("Controls:\n"
                       "S - Start game\n"
                       "P - Pause\n"
                       "Q - Quit\n"
                       "A - Left\n"
                       "D - Right\n"
                       "W - Rotate\n"
                       "Space - Drop");
    controls.setPosition(offsetX + boardWidthPx + 20, offsetY + 100);
    window.draw(controls);

    window.display();
}
