#include "Plant.h"

const std::array<std::string, 5> Plant::plantTypeNames = 
{
    "Empty",
    "Hornflower",
    "Bombflower",
    "Coinflower",
    "Healflower"
};

// int Plant::max_hp_ = 0;
// int Plant::count_of_plant_ = 0;

Plant::Plant() : cost_(0), hp_(0) {}

// manual: Plant plant(50, 75, PlantType::BOMB);
// Plant::Plant(int cost, int hp, PlantType type) : cost_(cost), hp_(hp), type_(type) {}
Plant::Plant(const int& cost, const int& hp) : cost_(cost), hp_(hp) {}

Plant::~Plant()
{
    
}

const int& Plant::getHP() const
{
    return this->hp_;
}

const int& Plant::getCost() const
{
    return this->cost_;
}

void Plant::beHealed(const int& healPoint)
{
    this->hp_ += healPoint;
}

void Plant::beInjured(const int& injuryPoint)
{
    this->hp_ -= injuryPoint;
}

bool Plant::isAlive() const
{
    return (this->hp_ > 0);
}

std::ostream& operator<<(std::ostream& os, const Plant& plant)
{
    if(plant.isAlive())
    {
        os << plant.getTypeName() << " HP: " << plant.getHP();
    }
    else
    {
        os << "Empty ";
    }
    return os;
}