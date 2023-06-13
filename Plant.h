#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
#include <array>

// Plant class
enum class PlantType
{
    EMPTY = 0,
    HORN, 
    BOMB, 
    COIN, 
    HEAL
};

class Plant
{
    public:
        // Plant(int cost, int hp, PlantType type);
        Plant();
        Plant(const int& hp);
        const int& getHP() const;
        void beHealed(const int& healPoint);
        void beInjured(const int& injuryPoint);
        bool isAlive() const;
        virtual ~Plant() {};
        // pure virtual function
        virtual const std::string& getTypeName() const {return plantTypeNames[static_cast<int>(PlantType::EMPTY)];}
        virtual const void showDetail() const {return ;}
        virtual const int getCost() const {return 0;}
        virtual const int getMaxHP() const {return 0;}
        // virtual function
        // return damage that applied to zombies
        virtual int meetZombies() const {return 0;}
        // return heal or coin point
        virtual int meetPlayers_heal() {return 0;}
        virtual int meetPlayers_coin() {return 0;}
        // for Coin
        virtual int rewardPoint() const {return 0;}
        virtual int targetTimes() const {return 0;}
        // for heal
        virtual int healPoint() const {return 0;}
        static std::array<std::string, 5> plantTypeNames;
    private:
        int hp_;
};

std::ostream& operator<<(std::ostream& os, const Plant& plant);

#endif
