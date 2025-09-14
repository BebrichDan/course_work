#ifndef PROGRESS_H
#define PROGRESS_H

class Progress {
public:
    Progress();

    void addScore(int linesCleared);
    int getScore() const;
    int getLevel() const;
    bool isGameOver() const;
    void setGameOver(bool state);
    void resetScore();

    void setLevel(int lvl);
private:
    int score;
    int level;
    bool gameOver;
};

#endif // PROGRESS_H
