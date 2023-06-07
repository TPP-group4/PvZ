#include "Plant.h"

const std::array<std::string, 5> Plant::plantTypeNames = 
{
    "Hornflower",
    "Bombflower",
    "Coinflower",
    "Healflower"
};

size_t Plant::max_hp_ = 0;
size_t Plant::count_of_plant_ = 0;

// manual: Plant plant(50, 75, PlantType::BOMB);
Plant::Plant(size_t cost, size_t hp, PlantType type) : cost_(cost), hp_(hp), type_(type) {}

const int& Plant::getHP() const
{
    return this->hp_;
}

const int& Plant::getCost() const
{
    return this->cost_;
}

void Plant::beHealed(const size_t& healPoint)
{
    this->hp_ += healPoint;
}

const std::string& Plant::getTypeName() const
{
    return plantTypeNames[static_cast<int>(this->type_)];
}