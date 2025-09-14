#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>

class ScoreManager {
private:
    int score;
    int highScore;
    std::string filename;

public:
    ScoreManager(const std::string& file = "high_score.txt");

    void addScore(int linesCleared);
    int getScore() const;
    int getHighScore() const;
    void resetScore();
    void saveHighScore();
    void loadHighScore();
};

#endif
