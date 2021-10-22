class ParkingSystem {
	int space[3] = {0};
public:
    ParkingSystem(int big, int medium, int small) {
    	space[0] = big;
        space[1] = medium;
        space[2] = small;
    }
    
    bool addCar(int carType) {
    	if(space[carType - 1]) {
            space[carType]--;
            return true;
        }

    	return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */