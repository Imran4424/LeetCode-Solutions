class ParkingSystem {
	int smallCount = 0;
	int mediumCount = 0;
	int bigCount = 0;
public:
    ParkingSystem(int big, int medium, int small) {
    	smallCount = small;
    	mediumCount = medium;
    	bigCount = big;
    }
    
    bool addCar(int carType) {
    	if (1 == carType) {
    		if (bigCount) {
    			bigCount--;
    			return true;
    		}
    	} else if (2 == carType) {
    		if (mediumCount) {
    			mediumCount--;
    			return true;
    		}
    	} else {
    		if (smallCount) {
    			smallCount--;
    			return true;
    		}
    	}

    	return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */