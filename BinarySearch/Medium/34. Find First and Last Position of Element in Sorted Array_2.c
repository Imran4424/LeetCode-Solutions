


int findElement(int* nums, int numsSize, int target) {
	int low = 0;
	int high = numsSize - 1;

	while(low < high) {
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
}
