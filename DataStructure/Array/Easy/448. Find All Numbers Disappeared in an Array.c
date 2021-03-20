

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	if (0 == numsSize) {
		*returnSize = 0;
		return nums;
	}

	int status[numsSize + 1]; 
	for (int i = 0; i <= numsSize; i++) {
		status[i] = 0;
	}

	for (int i = 0; i < numsSize; i++) {
		status[nums[i]] = 1;
	}

	int *disArr = malloc(numsSize * sizeof(int));
	int index = 0;

	for (int i = 1; i <= numsSize; i++) {
		if (0 == status[i]) {
			disArr[index++] = i;
		}
	}

	*returnSize = index;
	return disArr;
}