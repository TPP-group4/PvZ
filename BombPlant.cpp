#include "BombPlant.h"

int BombPlant::damage_ = 0;
int BombPlant::cost_ = 0;

BombPlant::BombPlant(const int& cost, const int& hp) : Plant(hp) 
{
    BombPlant::damage_ = hp;
    BombPlant::cost_ = cost;
}
// BombPlant end