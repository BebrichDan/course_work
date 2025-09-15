#include <SFML/Graphics.hpp>
#include "board.h"
#include "tetrominoFactory.h"
#include "renderer_sfml.h"
#include "player.h"
#include "progress.h"
#include "gameController.h"
#include "scoreManager.h"
#include <chrono>
#include <iostream>

std::string getPlayerName(sf::RenderWindow& window, sf::Font& font) {
    std::string name;
    sf::Text inputText("", font, 28);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(100, 300);

    sf::Text hint("Enter your name and press Enter:", font, 24);
    hint.setFillColor(sf::Color::Yellow);
    hint.setPosition(100, 250);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return "Player";
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') {
                    if (!name.empty()) name.pop_back();
                } else if (event.text.unicode == '\r') {
                    if (!name.empty()) return name;
                } else if (event.text.unicode < 128 && event.text.unicode >= 32) {
                    name += static_cast<char>(event.text.unicode);
                }
            }
        }

        window.clear(sf::Color::Black);
        inputText.setString(name + "|");
        window.draw(hint);
        window.draw(inputText);
        window.display();
    }
    return "Player";
}

void showStartScreen(sf::RenderWindow& window, sf::Font& font) {
    sf::Text title("TETRIS", font, 64);
    title.setFillColor(sf::Color::Cyan);
    title.setStyle(sf::Text::Bold);
    title.setPosition(200, 200);

    sf::Text prompt("Press S to start", font, 32);
    prompt.setFillColor(sf::Color::White);
    prompt.setPosition(220, 350);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                return;
            }
        }

        window.clear(sf::Color::Black);
        window.draw(title);
        window.draw(prompt);
        window.display();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 700), "Tetris");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Не удалось загрузить шрифт!" << std::endl;
        return 1;
    }

    std::string playerName = getPlayerName(window, font);
    Player player(playerName);

    showStartScreen(window, font);

    Board board(10, 20);
    TetrominoFactory factory;
    Progress progress;
    GameController controller(board, factory, progress);
    ScoreManager scoreManager("highscore.txt");
    RendererSFML renderer(board);

    bool isRunning = false;
    bool isPaused = false;

    auto lastFallTime = std::chrono::steady_clock::now();
    const float fallDelay = 0.5f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                scoreManager.saveHighScore();
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Q) {
                    scoreManager.saveHighScore();
                    window.close();
                }
                if (event.key.code == sf::Keyboard::S) {
                    // старт или рестарт
                    isRunning = true;
                    isPaused = false;
                    progress.resetScore();
                    progress.setGameOver(false);
                    board.clearGrid();
                    scoreManager.resetScore();
                    lastFallTime = std::chrono::steady_clock::now();
                }
                if (event.key.code == sf::Keyboard::P) {
                    if (isRunning && !progress.isGameOver()) {
                        isPaused = !isPaused;
                    }
                }

                if (isRunning && !isPaused && !progress.isGameOver()) {
                    if (event.key.code == sf::Keyboard::Left) controller.moveLeft();
                    if (event.key.code == sf::Keyboard::Right) controller.moveRight();
                    if (event.key.code == sf::Keyboard::Space) controller.rotate();
                    if (event.key.code == sf::Keyboard::Down) controller.drop();
                }
            }
        }

        if (isRunning && !isPaused && !progress.isGameOver()) {
            auto now = std::chrono::steady_clock::now();
            std::chrono::duration<float> elapsed = now - lastFallTime;

            if (elapsed.count() > fallDelay) {
                controller.update();
                lastFallTime = now;
            }
        }

        if (progress.isGameOver()) {
            scoreManager.updateHighScore(progress.getScore(), player.getName());
        }

        renderer.render(window, controller.getCurrentPiece(), player, progress, scoreManager);
    }

    return 0;
}