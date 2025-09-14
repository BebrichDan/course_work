#include <SFML/Graphics.hpp>
#include "board.h"
#include "tetrominoFactory.h"
#include "renderer_sfml.h"
#include "player.h"
#include "progress.h"
#include "gameController.h"
#include <chrono>

int main() {
    Board board(10, 20);
    TetrominoFactory factory;
    Player player("Player");
    Progress progress;
    GameController controller(board, factory, progress);

    sf::RenderWindow window(sf::VideoMode(800, 700), "Tetris");
    window.setFramerateLimit(60);

    RendererSFML renderer(board);

    bool isRunning = false;
    bool isPaused = false;

    auto lastFallTime = std::chrono::steady_clock::now();
    const float fallDelay = 0.5f; // скорость падения (сек)

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Q) {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::S) {
                    isRunning = true;
                    isPaused = false;
                }
                if (event.key.code == sf::Keyboard::P) {
                    isPaused = !isPaused;
                }

                if (isRunning && !isPaused) {
                    if (event.key.code == sf::Keyboard::A) controller.moveLeft();
                    if (event.key.code == sf::Keyboard::D) controller.moveRight();
                    if (event.key.code == sf::Keyboard::W) controller.rotate();
                    if (event.key.code == sf::Keyboard::Space) controller.drop();
                }
            }
        }

        if (isRunning && !isPaused) {
            auto now = std::chrono::steady_clock::now();
            std::chrono::duration<float> elapsed = now - lastFallTime;

            if (elapsed.count() > fallDelay) {
                controller.update(); // фигура падает вниз
                lastFallTime = now;
            }
        }

        renderer.render(window, controller.getCurrentPiece(), player, progress);
    }

    return 0;
}
