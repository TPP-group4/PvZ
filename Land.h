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