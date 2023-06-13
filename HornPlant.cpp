#include "HornPlant.h"

int HornPlant::damage_ = 0;
int HornPlant::cost_ = 0;
int HornPlant::maxHP_ = 0;

HornPlant::HornPlant(const int& cost, const int& hp, const int& damage) : Plant(hp)
{
    HornPlant::damage_ = damage;
    HornPlant::cost_ = cost;
    HornPlant::maxHP_ = hp;
}
// HornPlant end