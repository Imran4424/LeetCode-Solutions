
int pathCount[1000] = {-1};

int climbStairs(int number) {
	if(-1 != pathCount[number]) {
		return pathCount[number];
	}

	if(0 == number || 1 == number) {
		return pathCount[number] = 1;
	}

	return pathCount[number] = climbStairs(number - 1) + climbStairs(number - 2);
}