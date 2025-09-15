#include "scoreManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

ScoreManager::ScoreManager(const std::string& file) 
    : score(0), highScore(0), highScorePlayer("Unknown"), filename(file) {
    loadHighScore();
}

void ScoreManager::addScore(int linesCleared) {
    score += linesCleared * 100;
    // имя при addScore мы не знаем → рекорд обновляется только в main при Game Over
}

int ScoreManager::getScore() const {
    return score;
}

int ScoreManager::getHighScore() const {
    return highScore;
}

std::string ScoreManager::getHighScorePlayer() const {
    return highScorePlayer;
}

void ScoreManager::resetScore() {
    score = 0;
}

void ScoreManager::saveHighScore() {
    std::ofstream out(filename);
    if (out.is_open()) {
        out << highScore << "-" << highScorePlayer;
    }
}

void ScoreManager::loadHighScore() {
    std::ifstream in(filename);
    if (in.is_open()) {
        std::string line;
        if (std::getline(in, line)) {
            std::istringstream ss(line);
            std::string scoreStr, player;
            if (std::getline(ss, scoreStr, '-') && std::getline(ss, player)) {
                try {
                    highScore = std::stoi(scoreStr);
                    highScorePlayer = player;
                } catch (...) {
                    highScore = 0;
                    highScorePlayer = "Unknown";
                }
            }
        }
    } else {
        highScore = 0;
        highScorePlayer = "Unknown";
    }
}

void ScoreManager::updateHighScore(int newScore, const std::string& playerName) {
    if (newScore > highScore) {
        highScore = newScore;
        highScorePlayer = playerName;
        saveHighScore();
    }
}