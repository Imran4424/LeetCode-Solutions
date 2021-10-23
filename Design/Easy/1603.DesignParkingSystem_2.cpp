class ParkingSystem {
	int space[4] = {0};
public:
    ParkingSystem(int big, int medium, int small) {
    	space[1] = big;
        space[2] = medium;
        space[3] = small;
    }
    
    bool addCar(int carType) {
    	if(space[carType]) {
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