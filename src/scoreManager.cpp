#include "scoreManager.h"
#include <fstream>
#include <iostream>

ScoreManager::ScoreManager(const std::string& file) 
    : score(0), highScore(0), filename(file) {
    loadHighScore();
}

void ScoreManager::addScore(int linesCleared) {
    score += linesCleared * 100;
    updateHighScore(score);
}

int ScoreManager::getScore() const {
    return score;
}

int ScoreManager::getHighScore() const {
    return highScore;
}

void ScoreManager::resetScore() {
    score = 0;
}

void ScoreManager::saveHighScore() {
    std::ofstream out(filename);
    if (out.is_open()) {
        out << highScore;
    }
}

void ScoreManager::loadHighScore() {
    std::ifstream in(filename);
    if (in.is_open()) {
        in >> highScore;
    } else {
        highScore = 0;
    }
}

void ScoreManager::updateHighScore(int newScore) {
    if (newScore > highScore) {
        highScore = newScore;
        saveHighScore();
    }
}