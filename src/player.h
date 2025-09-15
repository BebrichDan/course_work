#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;

public:
    Player(const std::string& name = "Player");

    void setName(const std::string& newName);
    std::string getName() const;

};

#endif
