#include "HornPlant.h"

HornPlant::HornPlant(const int& cost, const int& hp, const int& damage) : Plant(cost, hp), damage_(damage) {}

const int& HornPlant::getDamage() const
{
    return this->damage_;
}