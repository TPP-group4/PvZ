#include "Land.h"
#include <vector>

class Map {
	public:
		Map();	//default number of lands
	    Map(int numLands);	//number of lands is selected

	    Land& getLand(int index);
	    int getNumLands() const;
    private:
    	std::vector<Land> lands_;
};