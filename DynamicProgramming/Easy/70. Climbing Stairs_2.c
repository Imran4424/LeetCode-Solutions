/*
	this type of initialization only works
	
	if the initialization value is 0

*/
int pathCount[100] = {0};

int climbStairs(int number) {
	if(0 != pathCount[number]) {
		return pathCount[number];
	}
    
	if(0 == number || 1 == number) {
		return pathCount[number] = 1;
	}

	return pathCount[number] = climbStairs(number - 1) + climbStairs(number - 2);
}