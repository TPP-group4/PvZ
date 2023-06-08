#ifndef HORNPLANT_H
#define HORNPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

class HornPlant : public Plant
{
    public:
        HornPlant(const size_t& cost, const size_t& hp, const size_t& damage);
        const size_t& getDamage() const;
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HORN)];
        }
    private:
        size_t damage_;
};

#endif