#include "Zombie.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>  // For rand and srand

Zombie::Zombie() : health_(15), currentLandIndex_(0) {}	//default health
Zombie::Zombie(int initialHealth) : health_(initialHealth), currentLandIndex_(0) {}	//health is selected

void Zombie::decreaseHealth(int amount)
{
    health_ -= amount;
}

int Zombie::getHealth() const
{
    return health_;
}

void Zombie::move()
{
    int steps = rand() % 3 + 1;
    int land_size = Game::getInstance()->getMap().getlen();
    currentLandIndex_ = (currentLandIndex_ + steps) % land_size;
    std::cout << "move" << std::endl;
}

int Zombie::getCurrentLandIndex() const
{
    return currentLandIndex_;
}
