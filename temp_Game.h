//測試用的class, 阿ㄨㄣˊ你加油參考一下

#include "Map.h"
#include "Player.h"
#include "Zombie.h"
#include "temp_Plant.h"
#include "Land.h"
#include <vector>

class Game {
private:
    Map map;
    Player player;
    std::vector<Zombie> zombies;

public:
    Game(int numLands, int initialMoney, const std::vector<Zombie>& initialZombies)
        : map(numLands), player(initialMoney), zombies(initialZombies) {}

    void processPlayerTurn(int landIndex, Plant* plant) {
        if (plant) {
            map.getLand(landIndex).setPlant(plant);
            player.decreaseMoney(plant->getHealth());
        }

        // Check if player has encountered a particular plant twice
        // and increase money if necessary

        // Check if player has encountered another particular plant
        // and increase health of all plants on the map if necessary
    }

    void processZombieTurn(int landIndex) {
        Land& land = map.getLand(landIndex);

        if (land.hasPlant()) {
            Plant* plant = land.getPlant();
            plant->decreaseHealth(1);
        } else {
            // Zombie attacks the player or performs other actions
        }
    }
};
////////////////////////////////////////////////////////////////////////////////