#include "HornPlant.h"

HornPlant::HornPlant(const size_t& cost, const size_t& hp, const size_t& damage) : Plant(cost, hp), damage_(damage) {}

const size_t& HornPlant::getDamage() const
{
    return this->damage_;
}