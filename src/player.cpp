#include "player.h"

Player::Player(const std::string& name) : name(name) {}

void Player::setName(const std::string& newName) { name = newName; }
std::string Player::getName() const { return name; }