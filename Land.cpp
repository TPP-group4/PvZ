#include "Land.h"

Land::Land() : plant_(nullptr) {}

void Land::setPlant(Plant* p)
{
    plant_ = p;
}

Plant* Land::getPlant() const
{
    return plant_;
}

bool Land::hasPlant() const
{
    return plant_ != nullptr;
}