#include "BombPlant.h"

BombPlant::BombPlant(const int& cost, const int& hp) : Plant(cost, hp), damage_(hp) {}

const int& BombPlant::myDamage() const
{
    return this->damage_;
}