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
    HornPlant a(10, 20, 30);
    unordered_map<int, Plant*> map;
    map[0] = &a;
    cout << *map[0] << endl;
}