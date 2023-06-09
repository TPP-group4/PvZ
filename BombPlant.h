#ifndef BOMBPLANT_H
#define BOMBPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

class BombPlant : public Plant
{
    public:
        BombPlant(const int& cost, const int& hp);
        const int& myDamage() const;
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::BOMB)];
        }
    private:
        const int damage_;
};

#endif