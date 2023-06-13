#include "Game.h"
#include <ctime>    // For time

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Initialize random seed

    //Map map;
    Game *gm = Game::getInstance();
    gm->read_file();
    gm->Init();
    gm->PrintZombieInformations();
    
    return 0;
}
