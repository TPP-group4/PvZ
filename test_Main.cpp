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
        gm->PrintPlant();
        int option ;
        cout << "player $150:    Enter your choice (4 to give up, default: 4)...>";

        if (std::cin.peek() == '\n') {
            option = 4;
            std::cin.ignore();  // 忽略换行符
        } 
        else {
            std::cin >> option;
        }
        gm->plant(option);
        gm->Turn();
    }
    
    
    return 0;
}
