#include "BombPlant.h"

BombPlant::BombPlant(const size_t& cost, const size_t& hp) : Plant(cost, hp), damage_(hp) {}

const int& BombPlant::myDamage() const
{
    return this->damage_;
}