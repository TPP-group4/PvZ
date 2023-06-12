#ifndef COINPLANT_H
#define COINPLANT_H

#include <iostream>
#include <string>
#include "Plant.h"

// CoinPlant
class CoinPlant : public Plant
{
    public:
        CoinPlant(const int& cost, const int& hp, const int& reward, const int& tarVisTimes);
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::COIN)];
        }
        virtual const void showDetail() const
        {
            std::cout << this->getTypeName() << " $" << CoinPlant::cost_ << " HP:" << CoinPlant::maxHP_ << " - gives $" << CoinPlant::reward_ << " every " << CoinPlant::targetVisTimes_ << " rounds" <<std::endl;
        }
        virtual int meetPlayers() override
        {
            ++this->visTimes_;
            if(this->visTimes_ == this->targetVisTimes_)
            {
                visTimes_ = 0;
                return this->reward_;
            }
            return 0;
        }
    private:
        static int targetVisTimes_;
        static int reward_;
        static int cost_;
        static int maxHP_;
        int visTimes_;
};

#endif