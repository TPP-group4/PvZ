#include "Game.h"
#include <ctime>    // For time

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Initialize random seed

    //Map map;
    Game *gm = Game::getInstance();
    gm->read_file();
    gm->Init();
    cin.get();
    while (1)
    {
        gm->printMap();
        gm->PrintZombieInformations();
        int option ;
        cout << "player $150:    Enter your choice (4 to give up, default: 4)...>";
        cin >> option;
        gm->plant(option);
        gm->Turn();
    }
    
    
    return 0;
}
