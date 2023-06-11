#ifndef LAND_H
#define LAND_H

//class Plant;
#include "temp_Plant.h"
class Land {
	public:
	    Land();
	    void setPlant(Plant* p);
	    Plant* getPlant() const;
	    bool hasPlant() const;
    private:
    	Plant* plant_;
};

#endif
