

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
	int *newNums = malloc(numsSize * sizeof(int));

	int i, j, index = 0;
	for(i = 0, j = n; index < numsSize - 1; i++, j++) {
		newNums[index++] = nums[i];
		newNums[index++] = nums[j];
	}

	*returnSize = numsSize;
	return newNums;
}