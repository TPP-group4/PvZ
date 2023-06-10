#include "Map.h"

class Player {
	public:
		Player();	//default money
	    Player(int initialMoney);	//money is selected

	    void decreaseMoney(int amount);

	    void increaseMoney(int amount);

	    int getMoney() const;

	    void move( const Map map);

	    int getCurrentLandIndex() const;

    private:
	    int money_;
	    int currentLandIndex_;

};