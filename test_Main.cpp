#include "temp_Game.h"
#include <ctime>    // For time

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Initialize random seed

    // Example usage
    Player player;
    Zombie zombie1;
    Zombie zombie2;
    std::vector<Zombie> zombies = {zombie1, zombie2};

    Map map;	//default nember of land
//  Map map(10) //number of land is selected


    Plant plant("Sunflower", 5); //For test, 這邊是用 string輸入，要修改成品翰的格式

	//For test
    Game game(map.getNumLands(), player.getMoney(), zombies);

    player.move(map);  // Player moves randomly between 1 to 6 steps
    int currentPlayerLand = player.getCurrentLandIndex();
    game.processPlayerTurn(currentPlayerLand, &plant); //For test

    zombie1.move(map);  // Zombie moves randomly between 1 to 3 steps
    int currentZombieLand = zombie1.getCurrentLandIndex();
    game.processZombieTurn(currentZombieLand);	//For test

    return 0;
}
