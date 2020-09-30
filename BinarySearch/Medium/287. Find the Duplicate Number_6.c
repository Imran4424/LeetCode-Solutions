



int findDuplicate(int* nums, int numsSize) {
	int low = 0;
	int high = numsSize - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		int count = 0;
		for (int i = 0; i < numsSize; i++) {
			if (nums[i] <= mid) {
				count++;
			}
		}

		if (count <= mid) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}

	return low;
}