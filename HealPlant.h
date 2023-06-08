#ifndef HEALPLANT_H
#define HEALPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

class HealPlant : public Plant
{
    public:
        HealPlant(const size_t& cost, const size_t& hp, const size_t& healPoint);
        const int& myHealPoint() const;
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HEAL)];
        }
    private:
        int healPoint_;
};

#endif