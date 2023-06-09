#ifndef HORNPLANT_H
#define HORNPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

class HornPlant : public Plant
{
    public:
        HornPlant(const int& cost, const int& hp, const int& damage);
        const int& getDamage() const;
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HORN)];
        }
    private:
        int damage_;
};

#endif