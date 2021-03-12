


void moveZeroes(int* nums, int numsSize) {
	int zeroIndex = 0;
	int nonZeroIndex = 0;

	for (int i = 0; i < numsSize; i++) {
		if (0 == nums[i]) {
			zeroIndex++;
		} else {
			nums[nonZeroIndex++] = nums[i];
		}
	}

	if (zeroIndex < numsSize) {
		for (int i = nonZeroIndex; i < numsSize ; i++) {
			nums[i] = 0;
		}
	}
}