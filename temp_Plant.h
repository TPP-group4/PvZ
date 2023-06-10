#ifndef PLANT_H
#define PLANT_H

#include <string>

//For test, 要用品翰的格式
class Plant {
    public:
        Plant(const std::string plantBreed, int plantHealth) : breed(plantBreed), health(plantHealth) {}

        void decreaseHealth(int amount) {
            health -= amount;
        }

        void increaseHealth(int amount) {
            health += amount;
        }

        int getHealth() const {
            return health;
        }

    private:
        std::string breed;
        int health;

};
#endif
//////////////////////////////////////////////////////////////////////////////////////////////