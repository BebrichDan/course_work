#include "scoreManager.h"
#include <fstream>

ScoreManager::ScoreManager(const std::string& file)
    : highScore(0), filename(file) {
    loadHighScore();
}

int ScoreManager::getHighScore() const {
    return highScore;
}

void ScoreManager::updateHighScore(int currentScore) {
    if (currentScore > highScore) {
        highScore = currentScore;
        saveHighScore();
    }
}

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
