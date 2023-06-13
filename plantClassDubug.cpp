#include <iostream>
#include <string>
#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <cstdlib>

// Plant class

class Plant
{
    public:
        // Plant(int cost, int hp, PlantType type);
        Plant();
        Plant(const int& hp);
        const int& getHP() const;
        void beHealed(const int& healPoint);
        void beInjured(const int& injuryPoint);
        bool isAlive() const;
        virtual ~Plant() {};
        // pure virtual function
        virtual const std::string& getTypeName() const {return plantTypeNames[static_cast<int>(PlantType::EMPTY)];}
        virtual const void showDetail() const {return ;}
        virtual const int getCost() const {return 0;}
        virtual const int getMaxHP() const {return 0;}
        // virtual function
        // return damage that applied to zombies
        virtual int meetZombies() const {return 0;}
        // return heal or coin point
        virtual int meetPlayers_heal() {return 0;}
        virtual int meetPlayers_coin() {return 0;}
        // for Coin
        virtual int rewardPoint() const {return 0;}
        virtual int targetTimes() const {return 0;}
        // for heal
        virtual int healPoint() const {return 0;}
        static std::array<std::string, 5> plantTypeNames;
    private:
        int hp_;
};

std::ostream& operator<<(std::ostream& os, const Plant& plant);

std::array<std::string, 5> Plant::plantTypeNames = 
{
    "Empty",
    "Hornflower",
    "Bombflower",
    "Coinflower",
    "Healflower"
};

Plant::Plant() : hp_(0) {}

// manual: Plant plant(50, 75, PlantType::BOMB);
// Plant::Plant(int cost, int hp, PlantType type) : cost_(cost), hp_(hp), type_(type) {}
Plant::Plant(const int& hp) : hp_(hp) {}

// Plant::~Plant()
// {
    
// }

const int& Plant::getHP() const
{
    return this->hp_;
}

void Plant::beHealed(const int& healPoint)
{
    this->hp_ += healPoint;
}

void Plant::beInjured(const int& injuryPoint)
{
    this->hp_ -= injuryPoint;
}

bool Plant::isAlive() const
{
    return (this->hp_ > 0);
}

std::ostream& operator<<(std::ostream& os, const Plant& plant)
{
    if(plant.isAlive())
    {
        os << plant.getTypeName() << " HP: " << plant.getHP();
    }
    else
    {
        os << "Empty ";
    }
    return os;
}
// Plant end

// HealPlant
class HealPlant : public Plant
{
    public:
        HealPlant(const int& cost, const int& hp, const int& healPoint);
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HEAL)];
        }
        virtual int meetPlayers_heal() override
        {
            return this->healPoint_;
        }
        virtual const void showDetail() const
        {
            std::cout << this->getTypeName() << " $" << HealPlant::cost_ << " HP:" << HealPlant::maxHP_ << " - gives all your plants " << HealPlant::healPoint_ << " HP back" << std::endl;
        }
        virtual int healPoint() const {std::cout << "|"; return HealPlant::healPoint_;}
        virtual const int getCost() const {return HealPlant::cost_;}
        virtual const int getMaxHP() const {return HealPlant::maxHP_;}
    private:
        static int healPoint_;
        static int cost_;
        static int maxHP_;
};

int HealPlant::healPoint_ = 0;
int HealPlant::cost_ = 0;
int HealPlant::maxHP_ = 0;
HealPlant::HealPlant(const int& cost, const int& hp, const int& healPoint) : Plant(hp)
{
    HealPlant::healPoint_ = healPoint;
    HealPlant::cost_ = cost;
    HealPlant::maxHP_ = hp;
}
// HealPlant end

// CoinPlant
class CoinPlant : public Plant
{
    public:
        CoinPlant(const int& cost, const int& hp, const int& reward, const int& tarVisTimes);
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::COIN)];
        }
        virtual const void showDetail() const
        {
            std::cout << this->getTypeName() << " $" << CoinPlant::cost_ << " HP:" << CoinPlant::maxHP_ << " - gives $" << CoinPlant::reward_ << " every " << CoinPlant::targetVisTimes_ << " rounds" <<std::endl;
        }
        virtual int meetPlayers_coin() override
        {
            ++this->visTimes_;
            if(this->visTimes_ == this->targetVisTimes_)
            {
                visTimes_ = 0;
                return this->reward_;
            }
            return 0;
        }
        virtual int rewardPoint() const {return CoinPlant::reward_;}
        virtual int targetTimes() const {return CoinPlant::targetVisTimes_;}
        virtual const int getCost() const {return CoinPlant::cost_;}
        virtual const int getMaxHP() const {return CoinPlant::maxHP_;}
    private:
        static int targetVisTimes_;
        static int reward_;
        static int cost_;
        static int maxHP_;
        int visTimes_;
};

int CoinPlant::targetVisTimes_ = 0;
int CoinPlant::reward_ = 0;
int CoinPlant::cost_ = 0;
int CoinPlant::maxHP_ = 0;
CoinPlant::CoinPlant(const int& cost, const int& hp, const int& reward, const int& tarVisTimes) : Plant(hp), visTimes_(0)
{
    CoinPlant::targetVisTimes_ = tarVisTimes;
    CoinPlant::reward_ = reward;
    CoinPlant::cost_ = cost;
    CoinPlant::maxHP_ = hp;
}
// CoinPlant end

// BombPlant
class BombPlant : public Plant
{
    public:
        BombPlant(const int& cost, const int& hp);
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::BOMB)];
        }
        virtual const void showDetail() const
        {
            std::cout << this->getTypeName() << " $" << BombPlant::cost_ << " HP:" << BombPlant::damage_ << " - gives " << BombPlant::damage_ << " damage points" << std::endl;
        }
        virtual int meetZombies() const override
        {
            return this->damage_;
        }
        virtual const int getCost() const {return BombPlant::cost_;}
        virtual const int getMaxHP() const {return BombPlant::damage_;}
    private:
        static int damage_;
        static int cost_;
};

int BombPlant::damage_ = 0;
int BombPlant::cost_ = 0;
BombPlant::BombPlant(const int& cost, const int& hp) : Plant(hp) 
{
    BombPlant::damage_ = hp;
    BombPlant::cost_ = cost;
}
// BombPlant end

// HornPlant
class HornPlant : public Plant
{
    public:
        HornPlant(const int& cost, const int& hp, const int& damage);
        virtual const std::string& getTypeName() const override
        {
            return plantTypeNames[static_cast<int>(PlantType::HORN)];
        }
        virtual int meetZombies() const override
        {
            return this->damage_;
        }
        virtual const void showDetail() const
        {
            std::cout << this->getTypeName() << " $" << HornPlant::cost_ << " HP:" << HornPlant::maxHP_ << " - gives " << HornPlant::damage_ << " damage points" << std::endl;
        }
        virtual const int getCost() const {return HornPlant::cost_;}
        virtual const int getMaxHP() const {return HornPlant::maxHP_;}
    private:
        static int damage_;
        static int cost_;
        static int maxHP_;
};

int HornPlant::damage_ = 0;
int HornPlant::cost_ = 0;
int HornPlant::maxHP_ = 0;
HornPlant::HornPlant(const int& cost, const int& hp, const int& damage) : Plant(hp)
{
    HornPlant::damage_ = damage;
    HornPlant::cost_ = cost;
    HornPlant::maxHP_ = hp;
}
// HornPlant end

// Zombie
class Map;
// class Zombie
// {
//     public:
//         Zombie();
//         // constructer for setup
//         Zombie(int cnt);
//         void beInjured(const int& injuryPoint);
//         const int& attack() const;
//         const int& getHP() const;
//         const int& getPos() const;
//         bool isAlive() const;
//         friend class Map;
//     private:
//         static constexpr int damage_ = 15;
//         int health_ = 40;
//         static int totalCNT;
//         static int currCNT;
//         int id_ = -1;
//         int zombie_loc_;
// };

// int Zombie::totalCNT = 0;
// int Zombie::currCNT = 0;
// Zombie::Zombie()
// {
//     for(int i = 0; i < Zombie::totalCNT; ++i)
//     {
//         this->id_ = i;
//         this->zombie_loc_ = rand() % Map::map_len_;
//         Map::board[i] = *this;
//         std::cout << i << ": " << Map::board[i].getHP();
//     }
// }

// Zombie::Zombie(int cnt)
// {
//     Zombie::totalCNT = cnt;
//     Zombie::currCNT = cnt;
//     for(int i = 0; i < Zombie::totalCNT; ++i)
//     {
//         this->id_ = i;
//         this->zombie_loc_ = rand() % Map::map_len_;
//         Map::board[i] = *this;
//         std::cout << i << ": " << Map::board[i].getHP();
//     }
// }

// bool Zombie::isAlive() const
// {
//     return (this->health_ > 0);
// }

// const int& Zombie::getPos() const
// {
//     return this->zombie_loc_;
// }

// void Zombie::beInjured(const int& injuryPoint)
// {
//     this->health_-=injuryPoint;
//     if(!(this->isAlive()))
//     {
//         --Zombie::currCNT;
//     }
// }
// const int& Zombie::attack() const
// {
//     return Zombie::damage_;
// }
// const int& Zombie::getHP() const
// {
//     return this->health_;
// }
// // Zombie end

// map 
class Player;

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
        void printMap();
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
// map end

// player
class Player
{
    public:
        Player();
        void increaseMoney(const int& reward);
        void decreaseMoney(const int& spend);
        void move(Map& tmp)
        {
            int steps = rand() % 6 + 1;     // Randomly generate steps between 1 and 6
            tmp.playerLoc_ = (tmp.playerLoc_+steps) % tmp.map_len_;
        }
    private:
        int money_;
};
void Player::increaseMoney(const int& reward)
{
    this->money_ += reward;
}
void Player::decreaseMoney(const int& spend)
{
    this->money_ -= spend;
}
// Player end

// game flow start
int main()
{
    // read plant detail
    // use virtual table to store basic info
    Plant* plantINFOTable[5] = {};
    int mapCount = 0;
    std::map<int, Plant*> INFOTable;

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
        for(const auto& it : INFOTable)
        {
            std::cout << "[" << it.first << "] ";
            it.second->showDetail();
        }
    }
    // read plant detail end

    Map grid;
    grid[0] = new BombPlant(plantINFOTable[static_cast<int>(PlantType::BOMB)]->getCost(), plantINFOTable[static_cast<int>(PlantType::BOMB)]->getMaxHP());
    std::cout << grid[0]->meetPlayers_heal() << std::endl;
    grid[0]->beInjured(grid[0]->getHP());
    grid.printMap();
}
