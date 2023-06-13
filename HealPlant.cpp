#include "HealPlant.h"

int HealPlant::healPoint_ = 0;
int HealPlant::cost_ = 0;
int HealPlant::maxHP_ = 0;

HealPlant::HealPlant(const int& cost, const int& hp, const int& healPoint) : Plant(hp)
{
    HealPlant::healPoint_ = healPoint;
    HealPlant::cost_ = cost;
    HealPlant::maxHP_ = hp;
}
// HealPlant end