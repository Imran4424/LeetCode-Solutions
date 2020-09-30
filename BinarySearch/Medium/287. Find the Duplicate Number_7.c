
/*
	if while condition is low <= high
	then, low = mid + 1, high = mid - 1;

	if while condition is low < high
	then, low = mid + 1, high = mid

	always remember the difference
*/


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
			high = mid - 1;
		}
	}

	return low;
}