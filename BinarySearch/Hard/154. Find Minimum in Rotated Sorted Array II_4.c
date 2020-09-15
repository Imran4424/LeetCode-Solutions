


int findMin(int* nums, int numsSize) {
	int low = 0;
	int high = numsSize - 1;

	while(low < high) {
		int mid = low + (high - low) / 2;

		if (nums[mid] > nums[high]) {
			low = mid + 1;
		} else if (nums[mid] < nums[high]) {
			high = mid;
		} else {
			high--;
		}

	}

	return nums[low];
}