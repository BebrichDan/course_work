#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int level;

public:
    Player(const std::string& name = "Player");

    void setName(const std::string& newName);
    std::string getName() const;

    void setLevel(int newLevel);
    int getLevel() const;

    void levelUp();
};

#endif
