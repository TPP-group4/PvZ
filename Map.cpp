#include "Map.h"

Map::Map() 
{
    Map::map_len_ = 8;
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