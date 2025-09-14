#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>

class ScoreManager {
public:
    ScoreManager(const std::string& file);

    void addScore(int linesCleared);
    int getScore() const;
    int getHighScore() const;

    void resetScore();

    void saveHighScore();
    void loadHighScore();

    void updateHighScore();

private:
    int score;
    int highScore;
    std::string filename;
};

#endif
