

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int *indexArr = malloc(2 * sizeof(int));

	indexArr[0] = indexArr[1] = -1;

	int index = 0;

	for (int i = 0; i < numsSize; i++) {
		if (target == nums[i]) {
			indexArr[index] = i;

			if(0 == index) {
				index++;
			}
		} else if(target < nums[i]) {
			break;
		}
	}

	if(-1 != indexArr[0] && -1 == indexArr[1]) {
		indexArr[1] = indexArr[0];
	}

	*returnSize = 2;

	return indexArr;
}

















