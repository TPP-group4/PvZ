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
        // Plant(size_t cost, size_t hp, PlantType type);
        Plant();
        Plant(const size_t& cost, const size_t& hp);
        const int& getHP() const;
        const int& getCost() const;
        void beHealed(const size_t& healPoint);
        void beInjured(const size_t& injuryPoint);
        bool isAlive() const;
        ~Plant();
    // protected:
        // PlantType type_;
        virtual const std::string& getTypeName() const
        {
            return plantTypeNames[static_cast<int>(PlantType::EMPTY)];
        }
        static const std::array<std::string, 5> plantTypeNames;
    private:
        int hp_;
        const int cost_;
        // static size_t max_hp_;
        // static size_t count_of_plant_;
        // static size_t count_of_alive_plant_;
        // static size_t count_of_bombplant_;
};

std::ostream& operator<<(std::ostream& os, const Plant& plant);

#endif