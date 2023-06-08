#include <HealPlant.h>

HealPlant::HealPlant(const size_t& cost, const size_t& hp, const size_t& healPoint) : Plant(cost, hp), healPoint_(healPoint) {}

const int& HealPlant::myHealPoint() const
{
    return this->healPoint_;
}