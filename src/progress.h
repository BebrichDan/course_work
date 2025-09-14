#ifndef PROGRESS_H
#define PROGRESS_H

class Progress {
private:
    int score;
    int level;
    bool gameOver;

public:
    Progress();

    void addScore(int linesCleared);
    int getScore() const;

    void setLevel(int lvl);
    int getLevel() const;

    void setGameOver(bool state);
    bool isGameOver() const;
};

#endif
