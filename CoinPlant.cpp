#include "CoinPlant.h"

int CoinPlant::targetVisTimes_ = 0;
int CoinPlant::reward_ = 0;
int CoinPlant::cost_ = 0;
int CoinPlant::maxHP_ = 0;

CoinPlant::CoinPlant(const int& cost, const int& hp, const int& reward, const int& tarVisTimes) : Plant(hp), visTimes_(0)
{
    CoinPlant::targetVisTimes_ = tarVisTimes;
    CoinPlant::reward_ = reward;
    CoinPlant::cost_ = cost;
    CoinPlant::maxHP_ = hp;
}
// CoinPlant end
