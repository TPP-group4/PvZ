#ifndef MAP_H
#define MAP_H
#include "Plant.h"
#include <map>
class Map
{
    public:
        Map();
        ~Map();
        Plant*& operator[] (int idx)
        {
            return maps[idx];
        }
        void erease(int idx)
        {
            maps.erase(idx);
            maps[idx] = new Plant;
        }
       	// void printMap();
        const int& getlen() {return map_len_;}
        friend class Player;
        friend class Zombie;
    private:
        std::map<int, Plant*> maps;
        // static std::map<int, Zombie> board;
        int map_len_ = 8;
        int playerLoc_;
};

// void Map::printMap()
// {
//     for(int i = 0; i < this->map_len_; ++i)
//     {
//         std::cout << "[" << i << "]{";
//         if(i == this->playerLoc_)
//         {
//             std::cout << "*";
//         }
//         else
//         {
//             std::cout << " ";
//         }
//         std::cout << "} "<< *maps[i] << std::endl;
//     }
// }

#endif