#ifndef HEALPLANT_H
#define HEALPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

class HealPlant : public Plant
{
    public:
        HealPlant(const int& cost, const int& hp, const int& healPoint);
        const int& myHealPoint() const;
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HEAL)];
        }
    private:
        int healPoint_;
};

#endif