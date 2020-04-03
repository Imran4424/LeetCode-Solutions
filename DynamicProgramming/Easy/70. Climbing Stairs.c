
int pathCount[1000] = {-1};

int climbStairs(int number) {
	if(-1 != pathCount[number]) {
		return pathCount[number];
	}
}