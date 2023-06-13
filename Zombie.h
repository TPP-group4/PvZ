#ifndef ZOMBIE_H
#define ZOMBIE_H
class Zombie {
	public:
		Zombie();//default health
	    Zombie(int initialHealth);	//health is selected

	    void decreaseHealth(int amount);
	    int getHealth() const;
	    void move();
	    int getCurrentLandIndex() const;

    private:
	    int health_;
	    int currentLandIndex_;
};
#endif