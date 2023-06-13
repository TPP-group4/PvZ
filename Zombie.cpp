#include "Zombie.h"

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

// void Zombie::move( const Map map)
// {
//     // int steps = rand() % 3 + 1;
//     // int land_size = map.getNumLands();
//     // currentLandIndex_ = (currentLandIndex_ + steps) % land_size;
// }

int Zombie::getCurrentLandIndex() const
{
    return currentLandIndex_;
}
