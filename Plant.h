#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
#include <array>

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
        Plant(const int& cost, const int& hp);
        const int& getHP() const;
        const int& getCost() const;
        void beHealed(const int& healPoint);
        void beInjured(const int& injuryPoint);
        bool isAlive() const;
        ~Plant();
    // protected:
        // PlantType type_;
        // pure virtual function
        virtual const std::string& getTypeName() const = 0;
        static const std::array<std::string, 5> plantTypeNames;
    private:
        int hp_;
        const int cost_;
        // static int max_hp_;
        // static int count_of_plant_;
        // static int count_of_alive_plant_;
        // static int count_of_bombplant_;
};

std::ostream& operator<<(std::ostream& os, const Plant& plant);

#endif