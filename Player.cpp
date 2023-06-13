#include "Player.h"

#include <cstdlib>  // For rand and srand

Player::Player() : money_(150), currentLandIndex_(0) {}	//default money
Player::Player(int initialMoney) : money_(initialMoney), currentLandIndex_(0) {}	//money is selected

void Player::decreaseMoney(int amount)
{
    money_ -= amount;
}

void Player::increaseMoney(int amount)
{
    money_ += amount;
}

int Player::getMoney() const
{
    return money_;
}

void Player::move()
{
    // int steps = rand() % 6 + 1;  // Randomly generate steps between 1 and 6
    // int land_size = map.getNumLands();
    // currentLandIndex_ = (currentLandIndex_ + steps) % land_size;  // Assuming 5 lands in the map
}

int Player::getCurrentLandIndex() const
{
    return currentLandIndex_;
}
