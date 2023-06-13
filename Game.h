//測試用的class, 阿ㄨㄣˊ你加油參考一下
#ifndef GAME_H
#define GAME_H
#include "Plant.h"
#include "BombPlant.h"
#include "HealPlant.h"
#include "HornPlant.h"
#include "CoinPlant.h"
#include "Zombie.h"

#include "Player.h"
#include "Map.h"

#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cstdlib>


class Game {
private:
    Plant* plantINFOTable[5] = {};
    int mapCount = 0;
    std::map<int, Plant*> INFOTable;
    std::vector <Zombie> zombies;
    static Game *instance;
    Player p;
    Map m;
public:
   static Game* getInstance()
    {
        
        if(instance == nullptr)
        {
            instance = new Game();
            return instance;
        }
        else
        {
            return instance;
        }
    }

public:
    Game(){};

    void Init(){
        std::cout << "Number of lands on the map [default = 8] :";
        int lands = 8;
        std::string num_land;
        std::getline( std::cin, num_land );
        if ( !num_land.empty() ) {
            std::istringstream stream( num_land );
            stream >> lands;
        }
        m.Init(lands);


        std::cout << "Number of zombies on the map [default = 3]: ";

        int number = 3;
        std::string input;
        std::getline( std::cin, input );
        if ( !input.empty() ) {
            std::istringstream stream( input );
            stream >> number;
        }

        for(int i = 0 ; i < number ; i++){
            Zombie z;
            AddZombies(z);
        }

        std::cout << "=============================================================================Plants vs. Zombies Rule: " << std::endl;
        std::cout << "How to win:" << std::endl;
        std::cout << "(1) All zombies are dead." << std::endl;
        std::cout << "(2) At least one plant is live." << std::endl;
        std::cout << "(3) The number of dead bomb plants cannot exceed the number of zombies." << std::endl;
        std::cout << std::endl;
        std::cout <<"How to lose:" << std::endl;
        std::cout <<"All plants are dead." << std::endl;
        std::cout <<"=============================================================================" << std::endl;

    }
    // void processPlayerTurn(int landIndex, Plant* plant) {
    //     if (plant) {
    //         map.getLand(landIndex).setPlant(plant);
    //         player.decreaseMoney(plant->beInjured());
    //     }

    //     // Check if player has encountered a particular plant twice
    //     // and increase money if necessary

    //     // Check if player has encountered another particular plant
    //     // and increase health of all plants on the map if necessary
    // }

    // void processZombieTurn(int landIndex) {
    //     Land& land = map.getLand(landIndex);

    //     if (land.hasPlant()) {
    //         Plant* plant = land.getPlant();
    //         plant->decreaseHealth(1);
    //     } else {
    //         // Zombie attacks the player or performs other actions
    //     }
    // }

    void read_file(){

        std::ifstream ifs;
        std::string line;

        ifs.open("plants.txt");
        if (ifs.is_open()) 
        {
            while (getline(ifs, line)) 
            {
                std::stringstream ss;
                std::string name = "";
                int hp = 0, cost = 0; 
                int reward = 0, aimvisitedTimes = 0, damagePoint = 0, healPoint = 0;
                ss << line << std::endl;
                char type;
                ss >> type;
                switch (type)
                {
                    case 'C':
                        ss >> name;
                        Plant::plantTypeNames[static_cast<int>(PlantType::COIN)] = name;
                        ss >> type >> cost >> hp >> aimvisitedTimes >> reward;
                        // call CoinPlant's constructer
                        plantINFOTable[static_cast<int>(PlantType::COIN)] = new CoinPlant(cost, hp, reward, aimvisitedTimes);
                        INFOTable[mapCount++] = new CoinPlant(cost, hp, reward, aimvisitedTimes);
                        break;
                    case 'S':
                        ss >> name;
                        Plant::plantTypeNames[static_cast<int>(PlantType::HORN)] = name;
                        ss >> type >> cost >> hp >> damagePoint;
                        // call HornPlant's constructer
                        plantINFOTable[static_cast<int>(PlantType::HORN)] = new HornPlant(cost, hp, damagePoint);
                        INFOTable[mapCount++] = new HornPlant(cost, hp, damagePoint);
                        break;
                    case 'B':
                        ss >> name;
                        Plant::plantTypeNames[static_cast<int>(PlantType::BOMB)] = name;
                        ss >> type >> cost >> hp;
                        // call BombPlant's constructer
                        plantINFOTable[static_cast<int>(PlantType::BOMB)] = new BombPlant(cost, hp);
                        INFOTable[mapCount++] = new BombPlant(cost, hp);
                        break;
                    case 'H':
                        ss >> name;
                        Plant::plantTypeNames[static_cast<int>(PlantType::HEAL)] = name;
                        ss >> type >> cost >> hp >> healPoint;
                        // call HealPlant's constructer
                        plantINFOTable[static_cast<int>(PlantType::HEAL)] = new HealPlant(cost, hp, healPoint);
                        INFOTable[mapCount++] = new HealPlant(cost, hp, healPoint);
                        break;
                    default :
                        std::cout << "unknow type" << std::endl;
                }
            }
            ifs.close();
            // show Plant INFO
            PrintPlant();
        }
    }

    void printMap();

    void AddZombies(Zombie z){
        zombies.push_back(z);
        return;
    }
    
    void PrintZombieInformations(){
        std::cout << "Zombie Information :" << std::endl;
        for(int i =0 ; i < zombies.size() ; i++){
            std::cout << "[" << i << "]" << "Damege : " << zombies[i].getHealth() << "HP" << std::endl;
        }
    }

    void PrintPlant(){
        for(const auto& it : INFOTable)
        {
            std::cout << "[" << it.first << "] ";
            it.second->showDetail();
        }
        return;
    }

    const Map &getMap()const{
        return m;
    }

    void plant(int option){
        switch (option)
        {
        case 0:
            m[p.getCurrentLandIndex()] = new CoinPlant(plantINFOTable[static_cast<int>(PlantType::COIN)]->getCost(), plantINFOTable[static_cast<int>(PlantType::COIN)]->getMaxHP(), plantINFOTable[static_cast<int>(PlantType::COIN)]->rewardPoint(), plantINFOTable[static_cast<int>(PlantType::COIN)]->targetTimes());
            break;
        case 1:
            m[p.getCurrentLandIndex()] = new HornPlant(plantINFOTable[static_cast<int>(PlantType::HORN)]->getCost(), plantINFOTable[static_cast<int>(PlantType::HORN)]->getMaxHP(), plantINFOTable[static_cast<int>(PlantType::HORN)]->meetZombies());
            break;
        case 2:
            m[p.getCurrentLandIndex()] = new BombPlant(plantINFOTable[static_cast<int>(PlantType::BOMB)]->getCost(), plantINFOTable[static_cast<int>(PlantType::BOMB)]->getMaxHP());
            break;
        case 3:
            m[p.getCurrentLandIndex()] = new HealPlant(plantINFOTable[static_cast<int>(PlantType::HEAL)]->getCost(), plantINFOTable[static_cast<int>(PlantType::HEAL)]->getMaxHP(), plantINFOTable[static_cast<int>(PlantType::HEAL)]->healPoint());
            break;
        default:
            break;
        }
    }
    
    void Turn(){
        p.move();
        for(Zombie &z : zombies){
            z.move();
            std::cin.get();
            printMap();
        }
        m.updatePlayerLoc(p.getCurrentLandIndex());
        return;
    }
};

#endif
////////////////////////////////////////////////////////////////////////////////