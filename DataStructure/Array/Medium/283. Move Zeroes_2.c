


void moveZeroes(int* nums, int numsSize) {
	int nonZeroIndex = 0;

	for (int i = 0; i < numsSize; i++) {
		if (0 != nums[i]) {
			nums[nonZeroIndex++] = nums[i];
		}
	}

	for (int i = nonZeroIndex; i < numsSize ; i++) {
		nums[i] = 0;
	}
}