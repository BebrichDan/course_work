#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>

class ScoreManager {
private:
    int highScore;
    std::string filename;

public:
    ScoreManager(const std::string& file);

    int getHighScore() const;
    void updateHighScore(int currentScore);

    void saveHighScore();
    void loadHighScore();
};

#endif
