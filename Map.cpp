#include "Map.h"
#include "Plant.h"

void Map::Init(int len){
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
void Map::printMap()
{
    for(int i = 0; i < this->map_len_; ++i)
    {
        std::cout << "[" << i << "]{";
        if(i == this->playerLoc_)
        {
            std::cout << "*";
        }
        else
        {
            std::cout << " ";
        }
        std::cout << "} "<< *maps[i] << std::endl;
    }
}
