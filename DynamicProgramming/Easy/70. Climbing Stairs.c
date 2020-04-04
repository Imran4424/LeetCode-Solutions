/*
	this type of initialization only works
	
	if the initialization value is 0

	otherwise this initialization won't work
*/
int pathCount[1000] = {-1};
// this initialization don't work

int climbStairsRecursive(int number) {
	if(-1 != pathCount[number]) {
		return pathCount[number];
	}

	if(0 == number || 1 == number) {
		return pathCount[number] = 1;
	}

	return pathCount[number] = climbStairsRecursive(number - 1) + climbStairsRecursive(number - 2);
}

int climbStairs(int number) {
	//
	for(int i = 0 ; i < 1000; i++) {
		pathCount[i] = -1;
	}

	return climbStairsRecursive(number);
}