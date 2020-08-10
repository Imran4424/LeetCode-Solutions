


int findElement(int* nums, int numsSize, int target) {
	int low = 0;
	int high = numsSize - 1;

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if(target == nums[mid]) {
			return mid;
		} else if(target > nums[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return -1;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int *indexArr = malloc(2 * sizeof(int));

	int index = findElement(nums, numsSize, target);

	indexArr[0] = indexArr[1] = index;

	if(-1 != index) {
		// left index
		for(int i = index - 1; i >= 0; i--) {
			if(target == nums[i]) {
				indexArr[0] = i;
			}
			else {
				break;
			}
		}

		// right index
		for(int i = index + 1; i < numsSize; i++) {
			if(target == nums[i]) {
				indexArr[1] = i;
			} else {
				break;
			}
		}
	}

	*returnSize = 2;
	return indexArr;
}

















