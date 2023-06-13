#ifndef HORNPLANT_H
#define HORNPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

// HornPlant
class HornPlant : public Plant
{
    public:
        HornPlant(const int& cost, const int& hp, const int& damage);
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HORN)];
        }
        virtual int meetZombies() const override
        {
            return this->damage_;
        }
        virtual const void showDetail() const
        {
            std::cout << this->getTypeName() << " $" << HornPlant::cost_ << " HP:" << HornPlant::maxHP_ << " - gives " << HornPlant::damage_ << " damage points" << std::endl;
        }
        virtual const int getCost() const override
        {
            return this->cost_;
        }
        virtual const int getMaxHP() const override
        {
            return this->maxHP_;
        }
    private:
        static int damage_;
        static int cost_;
        static int maxHP_;
};

#endif