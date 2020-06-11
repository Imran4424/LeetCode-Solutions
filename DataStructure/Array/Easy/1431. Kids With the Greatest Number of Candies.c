

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
	bool *canGreatest = malloc(candiesSize * sizeof(bool));

	int maxCandie = candies[0];
	for(int i = 1; i < candiesSize; i++) {
		if(candies[i] > maxCandie) {
			maxCandie = candies[i];
		}
	}
}