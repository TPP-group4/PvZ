#ifndef HEALPLANT_H
#define HEALPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

// HealPlant
class HealPlant : public Plant
{
    public:
        HealPlant(const int& cost, const int& hp, const int& healPoint);
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HEAL)];
        }
        virtual int meetPlayers_heal() override
        {
            return this->healPoint_;
        }
        virtual const void showDetail() const
        {
            std::cout << this->getTypeName() << " $" << HealPlant::cost_ << " HP:" << HealPlant::maxHP_ << " - gives all your plants " << HealPlant::healPoint_ << " HP back" << std::endl;
        }
        virtual int healPoint() const {std::cout << "|"; return HealPlant::healPoint_;}
        virtual const int getCost() const {return HealPlant::cost_;}
        virtual const int getMaxHP() const {return HealPlant::maxHP_;}
    private:
        static int healPoint_;
        static int cost_;
        static int maxHP_;
};

#endif