#include "Map.h"
#include <vector>

Map::Map() : lands_(8) {}	//default number of lands
Map::Map(int numLands) : lands_(numLands) {}	//number of lands is selected

Land& Map::getLand(int index)
{
    return lands_[index];
}

int Map::getNumLands() const
{
    return lands_.size();
}