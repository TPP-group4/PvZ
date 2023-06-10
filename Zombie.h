#include "Map.h"

class Zombie {
	public:
		Zombie();//default health
	    Zombie(int initialHealth);	//health is selected

	    void decreaseHealth(int amount);
	    int getHealth() const;
	    void move( const Map map);
	    int getCurrentLandIndex() const;

    private:
	    int health_;
	    int currentLandIndex_;
};