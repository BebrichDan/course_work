#include "player.h"

Player::Player(const std::string& name) : name(name), level(1) {}

void Player::setName(const std::string& newName) { name = newName; }
std::string Player::getName() const { return name; }

void Player::setLevel(int newLevel) { level = newLevel; }
int Player::getLevel() const { return level; }

void Player::levelUp() { level++; }
