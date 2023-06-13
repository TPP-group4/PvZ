#ifndef ZOMBIE_H
#define ZOMBIE_H
class Zombie {
	public:
		Zombie();//default health
	    Zombie(int initialHealth);	//health is selected

	    void decreaseHealth(int amount);
	    int getHealth() const;
		void spawn();
	    void move();
	    int getCurrentLandIndex() const;

		void updateDeath(){
			if(health_ < 0)
				is_dealth = true;
		}

		const bool is_Death() const {
			return is_dealth;
		}
		const int Damage()const{
			return 15;
		}

    private:
	    int health_;
	    int currentLandIndex_;
		bool is_dealth = false;
};
#endif