#include "scoreManager.h"
#include <fstream>

ScoreManager::ScoreManager(const std::string& file) : score(0), highScore(0), filename(file) {
    loadHighScore();
}

void ScoreManager::addScore(int linesCleared) {
    int points = 0;
    switch (linesCleared) {
        case 1: points = 100; break;
        case 2: points = 300; break;
        case 3: points = 700; break;
        case 4: points = 1500; break;
    }
    score += points;
    if (score > highScore) {
        highScore = score;
    }
}

int ScoreManager::getScore() const { return score; }
int ScoreManager::getHighScore() const { return highScore; }

void ScoreManager::resetScore() { score = 0; }

void ScoreManager::saveHighScore() {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}

void ScoreManager::loadHighScore() {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        highScore = 0;
    }
}
