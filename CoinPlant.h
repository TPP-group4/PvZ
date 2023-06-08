#ifndef COINPLANT_H
#define COINPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

class CoinPlant : public Plant
{
    public:
        CoinPlant(const size_t& cost, const size_t& hp, const int& reward, const int& visTimes);
        int visited();
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HEAL)];
        }
    private:
        const int& myreward() const;
        // static?
        const int targetVisTimes_;
        const int reward_;
        int visTimes_;
};

#endif