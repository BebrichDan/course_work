#include "renderer_sfml.h"
#include <iostream>

RendererSFML::RendererSFML(Board& b) : board(b) {
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Не удалось загрузить шрифт!" << std::endl;
    }
}

void RendererSFML::render(sf::RenderWindow& window,
                          const Tetromino& piece,
                          const Player& player,
                          const Progress& progress,
                          const ScoreManager& scoreManager) {
    window.clear(sf::Color::Black);

    // игра окончена 
    if (progress.isGameOver()) {
        sf::Text gameOverText("GAME OVER", font, 40);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setPosition(200, 200);
        window.draw(gameOverText);

        sf::Text scoreText("Score: " + std::to_string(progress.getScore()), font, 30);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(200, 260);
        window.draw(scoreText);

        // рекорд с именем рекордсмена
        std::string hsPlayer = scoreManager.getHighScorePlayer();
        if (hsPlayer.empty()) hsPlayer = "Unknown";
        sf::Text highScoreText(
            "High Score: " + std::to_string(scoreManager.getHighScore()) +
            " - " + hsPlayer,
            font, 30);
        highScoreText.setFillColor(sf::Color::Yellow);
        highScoreText.setPosition(200, 320);
        window.draw(highScoreText);

        // подсказки
        sf::Text restartText("Press S - restart\nPress Q - exit", font, 25);
        restartText.setFillColor(sf::Color::Cyan);
        restartText.setPosition(200, 400);
        window.draw(restartText);

        window.display();
        return;
    }

    const int tileSize = 30;
    const int offsetX = 50;
    const int offsetY = 50;

    // поле 
    sf::RectangleShape background(sf::Vector2f(board.getWidth() * tileSize,
                                               board.getHeight() * tileSize));
    background.setPosition(offsetX, offsetY);
    background.setFillColor(sf::Color(30, 30, 30));
    background.setOutlineThickness(2);
    background.setOutlineColor(sf::Color::White);
    window.draw(background);

    // клетки
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

    // фигура
    auto shape = piece.getShape();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j]) {
                sf::RectangleShape cell(sf::Vector2f(tileSize - 1, tileSize - 1));
                cell.setPosition(offsetX + (piece.getX() + j) * tileSize,
                                 offsetY + (piece.getY() + i) * tileSize);
                cell.setFillColor(sf::Color::Red);
                window.draw(cell);
            }
        }
    }

    // инфо
    sf::Text stats;
    stats.setFont(font);
    stats.setCharacterSize(20);
    stats.setFillColor(sf::Color::White);
    stats.setString("Score: " + std::to_string(progress.getScore()) +
                    "\nLevel: " + std::to_string(progress.getLevel()) +
                    "\nPlayer: " + player.getName());
    stats.setPosition(offsetX + board.getWidth() * tileSize + 20, offsetY);
    window.draw(stats);

    // рекорд (только число во время игры, имя показываем только на Game Over)
    sf::Text highScoreText("High Score: " + std::to_string(scoreManager.getHighScore()), font, 20);
    highScoreText.setFillColor(sf::Color::Yellow);
    highScoreText.setPosition(offsetX + board.getWidth() * tileSize + 20, offsetY + 100);
    window.draw(highScoreText);

    sf::Text controls;
    controls.setFont(font);
    controls.setCharacterSize(18);
    controls.setFillColor(sf::Color::Cyan);
    controls.setString("Controls:\n"
                   "Left  - Move Left\n"
                   "Right - Move Right\n"
                   "Down  - Soft Drop\n"
                   "Space - Rotate\n"
                   "P - Pause\n"
                   "Q     - Quit");
    controls.setPosition(offsetX + board.getWidth() * tileSize + 20, offsetY + 160);
    window.draw(controls);

    window.display();
}
