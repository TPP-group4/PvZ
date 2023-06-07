#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
#include <array>

enum class PlantType
{
    HORN, 
    BOMB, 
    COIN, 
    HEAL,
    EMPTY = 0
};

class Plant
{
    public:
        Plant(size_t cost, size_t hp, PlantType type);
        const int& getHP() const;
        const int& getCost() const;
        void beHealed(const size_t& healPoint);
        void beInjured(const size_t& injuryPoint);
        ~Plant();
    protected:
        PlantType type_;
        const std::string& getTypeName() const;
        static const std::array<std::string, 5> plantTypeNames;
    private:
        size_t hp_;
        const size_t cost_;
        static size_t max_hp_;
        // static size_t count_of_plant_;
};

#endif