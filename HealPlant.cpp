#include "HealPlant.h"

HealPlant::HealPlant(const int& cost, const int& hp, const int& healPoint) : Plant(cost, hp), healPoint_(healPoint) {}

const int& HealPlant::myHealPoint() const
{
    return this->healPoint_;
}