

/*
	Floyd's Tortoise and Hare (Cycle Detection)

	https://leetcode.com/problems/find-the-duplicate-number/solution/

	tortoise speed x
	hare speed 2x

	in the intesection point
	hare had travelled twice than the tortoise

	2d(tortoise) = d(hare) ex: 2 * 5 = 10
	2(F + a) = F + a + nC  
	(here, nC = loop or cycle, F = distance between first node and loop, 
	a = distance between loop and intersection point)
	F + a = nC

	F + a = C consider, n = 1

	F = C - a

	that means, 
	distance between first node and loop = distance between loop and intersection point

	put tortoise at the first node and hare at intersection point
	start the race with same speed x

*/


int findDuplicate(int* nums, int numsSize){
	int tortoise = nums[0];
	int hare = nums[0];

	do {
		tortoise = nums[tortoise];
		hare = nums[nums[hare]];
	} while (hare != tortoise);

	tortoise = nums[0];

	while (tortoise != hare) {
		tortoise = nums[tortoise];
		hare = nums[hare];
	}

	return hare;
}