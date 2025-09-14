#include "progress.h"

Progress::Progress() : score(0), level(1), gameOver(false) {}

void Progress::addScore(int linesCleared) {
    score += linesCleared * 100;

    // Простая логика увеличения уровня
    if (score >= level * 500) {
        level++;
    }
}

int Progress::getScore() const {
    return score;
}

void Progress::setLevel(int lvl) {
    level = lvl;
}

int Progress::getLevel() const {
    return level;
}

void Progress::setGameOver(bool state) {
    gameOver = state;
}

bool Progress::isGameOver() const {
    return gameOver;
}