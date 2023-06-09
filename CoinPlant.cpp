#include "CoinPlant.h"

CoinPlant::CoinPlant(const int& cost, const int& hp, const int& reward, const int& visTimes) : Plant(cost, hp), reward_(reward), targetVisTimes_(visTimes), visTimes_(0) {}

const int& CoinPlant::myreward() const
{
    return this->reward_;
}

int CoinPlant::visited()
{
    ++this->visTimes_;
    if(this->visTimes_ == this->targetVisTimes_)
    {
        visTimes_ = 0;
        return this->myreward();
    }
    return 0;
}
