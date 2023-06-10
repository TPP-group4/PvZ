#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For time

//For test, 要用品翰的格式 
class Plant {
private:
    std::string breed;
    int health;

public:
    Plant(std::string plantBreed, int plantHealth) : breed(plantBreed), health(plantHealth) {}

    void decreaseHealth(int amount) {
        health -= amount;
    }

    void increaseHealth(int amount) {
        health += amount;
    }

    int getHealth() const {
        return health;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////

class Land {
	public:
	    Land() : plant_(nullptr) {}
	
	    void setPlant(Plant* p) 
		{
	        plant_ = p;
	    }
	
	    Plant* getPlant() const 
		{
	        return plant_;
	    }
	
	    bool hasPlant() const 
		{
	        return plant_ != nullptr;
	    }
    
    private:
    	Plant* plant_;
};

class Map {
	public:
		Map() : lands_(8) {}	//default number of lands
	    Map(int numLands) : lands_(numLands) {}	//number of lands is selected
	
	    Land& getLand(int index) 
		{
	        return lands_[index];
	    }
	
	    int getNumLands() const 
		{
	        return lands_.size();
	    }
    
    private:
    	std::vector<Land> lands_;
};

class Player {
	public:
		Player() : money_(150), currentLandIndex_(0) {}	//default money
	    Player(int initialMoney) : money_(initialMoney), currentLandIndex_(0) {}	//money is selected
	
	    void decreaseMoney(int amount) 
		{
	        money_ -= amount;
	    }
	
	    void increaseMoney(int amount) 
		{
	        money_ += amount;
	    }
	
	    int getMoney() const 
		{
	        return money_;
	    }
	
	    void move( const Map map) 
		{
	        int steps = rand() % 6 + 1;  // Randomly generate steps between 1 and 6
	        int land_size = map.getNumLands();
	        currentLandIndex_ = (currentLandIndex_ + steps) % land_size;  // Assuming 5 lands in the map
	    }
	
	    int getCurrentLandIndex() const 
		{
	        return currentLandIndex_;
	    }
    
    private:
	    int money_;
	    int currentLandIndex_;

};

class Zombie {
	public:
		Zombie() : health_(15), currentLandIndex_(0) {}	//default health
	    Zombie(int initialHealth) : health_(initialHealth), currentLandIndex_(0) {}	//health is selected
	
	    void decreaseHealth(int amount) 
		{
	        health_ -= amount;
	    }
	
	    int getHealth() const 
		{
	        return health_;
	    }
	
	    void move( const Map map) 
		{
	        int steps = rand() % 3 + 1;
	        int land_size = map.getNumLands();
	        currentLandIndex_ = (currentLandIndex_ + steps) % land_size;  
	    }
	
	    int getCurrentLandIndex() const 
		{
	        return currentLandIndex_;
	    }
    
    private:
	    int health_;
	    int currentLandIndex_;
};

//測試用的class, 阿ㄨㄣˊ你加油參考一下 
class Game {
private:
    Map map;
    Player player;
    std::vector<Zombie> zombies;

public:
    Game(int numLands, int initialMoney, const std::vector<Zombie>& initialZombies)
        : map(numLands), player(initialMoney), zombies(initialZombies) {}

    void processPlayerTurn(int landIndex, Plant* plant) {
        if (plant) {
            map.getLand(landIndex).setPlant(plant);
            player.decreaseMoney(plant->getHealth());
        }

        // Check if player has encountered a particular plant twice
        // and increase money if necessary

        // Check if player has encountered another particular plant
        // and increase health of all plants on the map if necessary
    }

    void processZombieTurn(int landIndex) {
        Land& land = map.getLand(landIndex);

        if (land.hasPlant()) {
            Plant* plant = land.getPlant();
            plant->decreaseHealth(1);
        } else {
            // Zombie attacks the player or performs other actions
        }
    }
};
////////////////////////////////////////////////////////////////////////////////

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Initialize random seed

    // Example usage
    Player player;
    Zombie zombie1;
    Zombie zombie2;
    std::vector<Zombie> zombies = {zombie1, zombie2};
	
    Map map;	//default nember of land 
//  Map map(10) //number of land is selected 


    Plant plant("Sunflower", 5); //For test, 這邊是用 string輸入，要修改成品翰的格式 

	//For test
    Game game(map.getNumLands(), player.getMoney(), zombies);

    player.move(map);  // Player moves randomly between 1 to 6 steps
    int currentPlayerLand = player.getCurrentLandIndex();
    game.processPlayerTurn(currentPlayerLand, &plant); //For test

    zombie1.move(map);  // Zombie moves randomly between 1 to 3 steps
    int currentZombieLand = zombie1.getCurrentLandIndex();
    game.processZombieTurn(currentZombieLand);	//For test

    return 0;
}