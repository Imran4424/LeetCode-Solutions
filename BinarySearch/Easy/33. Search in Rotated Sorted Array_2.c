

int search(int* nums, int numsSize, int target){
	if (0 == numsSize) {
		return -1;
	}

	int low = 0;
	int high = numsSize - 1;

	while(low < high) {
		int mid = low + (high - low) / 2;

		// target and mid on the same side
		if ((nums[mid] - nums[numsSize - 1]) * (target - nums[numsSize - 1]) > 0) {
			if (nums[mid] < target) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
	}
}













