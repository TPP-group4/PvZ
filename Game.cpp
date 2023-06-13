#include "Game.h"
#include "Map.h"

Game* Game::instance = nullptr;

void Clear()
{
    #if defined _WIN32
        system("cls");
        //clrscr(); // including header file : conio.h
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void Game::printMap(){
    Clear();
    for(int i = 0; i < m.getlen(); ++i)
    {
        std::cout << "[" << i << "]{";
        if(i == m.getPlayerLoc())
        {
            std::cout << "*";
        }
        else
        {
            std::cout << " ";
        }
        for(int j =0 ; j < zombies.size() ; j++){
            if(i==zombies[j].getCurrentLandIndex())
                std::cout << j;
            else
                std::cout << " ";
        }
        std::cout << "} "<< *m[i] << std::endl;
    }
}