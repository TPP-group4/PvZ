#ifndef BOMBPLANT_H
#define BOMBPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

// BombPlant
class BombPlant : public Plant
{
    public:
        BombPlant(const int& cost, const int& hp);
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::BOMB)];
        }
        virtual const void showDetail() const
        {
            std::cout << this->getTypeName() << " $" << BombPlant::cost_ << " HP:" << BombPlant::damage_ << " - gives " << BombPlant::damage_ << " damage points" << std::endl;
        }
        virtual int meetZombies() const override
        {
            return this->damage_;
        }
        virtual const int getCost() const {return BombPlant::cost_;}
        virtual const int getMaxHP() const {return BombPlant::damage_;}
    private:
        static int damage_;
        static int cost_;
};

#endif