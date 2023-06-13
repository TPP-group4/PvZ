#include "Game.h"
#include <ctime>    // For time

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Initialize random seed

    //Map map;
    Game *gm = Game::getInstance();
    cout << "-----------------------------" << endl;
    cout << "|   Plants vs. Zombies      |" << endl;
    cout << "-----------------------------" << endl;
    gm->read_file();
    gm->Init();
    cin.get();
    while (!gm->is_End())
    {
        gm->printMap();
        gm->PrintZombieInformations();
        gm->PrintPlant();
        int option ;
        cout << "player $" << Game::getInstance()->getPlayer().getMoney() <<":    Enter your choice (4 to give up, default: 4)...>";

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
    if(gm->is_Win())
        cout << "PLANT Win" << endl;
    else{
        cout << "PLANT Lose" << endl;
    }

    return 0;
}
