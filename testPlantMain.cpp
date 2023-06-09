#include <iostream>
#include <unordered_map>
#include "Plant.h"
#include "HornPlant.h"
#include "HealPlant.h"
#include "BombPlant.h"
#include "CoinPlant.h"

using namespace std;

int main()
{
    // unordered_map<int, Plant*> map;

    // 印出上半部的辦法
    // test virtual fuction
    Plant* map[10];
    map[0] = new HornPlant(10, 20, 30);
    map[1] = new CoinPlant(50, 50, 100, 2);
    map[2] = new HealPlant(50, 50, 50);
    map[3] = new BombPlant(50, 50);
    cout << *map[0] << endl;
    cout << *map[1] << endl;
    cout << *map[2] << endl;
    cout << *map[3] << endl;
}