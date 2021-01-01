

int removeDuplicates(int* nums, int numsSize) {
	if (0 == numsSize || 1 == numsSize) {
		return numsSize;
	}

	int uniqueNums[numsSize];
	int index = 0;
	uniqueNums[index++] = nums[0];

	for (int i = 1; i < numsSize; i++) {
		if(uniqueNums[index - 1] != nums[i]) {
			uniqueNums[index++] = nums[i];
		}
	}

	for (int i = 0; i < index; i++) {
		nums[i] = uniqueNums[i];
	}


	return index;
}