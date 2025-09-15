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
    int getLevel() const;
    bool isGameOver() const;
    void setGameOver(bool state);
    void resetScore();

    void setLevel(int lvl);
};

#endif // PROGRESS_H
