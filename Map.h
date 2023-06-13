#ifndef MAP_H
#define MAP_H
#include "Plant.h"
#include <map>
class Map
{
    public:
        Map(int len = 8);
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
        static int map_len_;
        int playerLoc_;
};

int Map::map_len_ = 0;
Map::Map(int len) 
{
    Map::map_len_ = len;
    for(int i = 0; i < Map::map_len_; ++i)
    {
        maps[i] = new Plant;
    }
    playerLoc_ = 0;
}

Map::~Map()
{
    maps.clear();
}
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