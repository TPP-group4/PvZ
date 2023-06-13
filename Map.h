#ifndef MAP_H
#define MAP_H
#include "Plant.h"
#include <map>
class Map
{
    public:
        Map(){}
        ~Map();
        void Init(int len);
        Plant*& operator[] (int idx)
        {
            return maps[idx];
        }
        void erease(int idx)
        {
            maps.erase(idx);
            maps[idx] = new Plant;
        }
       	void printMap();
        const int& getlen() const {return map_len_;}
        friend class Player;
        friend class Zombie;
    public:
        void updatePlayerLoc(int p){
            playerLoc_ = p;
        }
        const int getPlayerLoc()const{
            return playerLoc_;
        }
    private:
        std::map<int, Plant*> maps;
        // static std::map<int, Zombie> board;
        int map_len_ = 8;
        int playerLoc_;
};
#endif