#include "progress.h"

Progress::Progress() : score(0), level(1), gameOver(false) {}

void Progress::addScore(int linesCleared) {
    int points = 0;
    switch (linesCleared) {
        case 1: points = 100; break;
        case 2: points = 300; break;
        case 3: points = 700; break;
        case 4: points = 1500; break;
    }
    score += points;

    if (score / 1000 >= level) {
        level++;
    }
}

int Progress::getScore() const {
    return score;
}

int Progress::getLevel() const {
    return level;
}

bool Progress::isGameOver() const {
    return gameOver;
}

void Progress::setGameOver(bool state) {
    gameOver = state;
}

void Progress::resetScore() {
    score = 0;
    level = 1;
    gameOver = false;
}

void Progress::setLevel(int lvl) {
    level = lvl;
}
