

int removeElement(int* nums, int numsSize, int val){
	if (0 == numsSize) {
		return numsSize;
	}

	int index = 0;
	int remainNums[numsSize];

	for (int i = 0; i < numsSize; i++) {
		if(val == nums[i]) {
			continue;
		}

		remainNums[index++] = nums[i];
	}

	for (int i = 0; i < index; i++) {
		nums[i] = remainNums[i];
	}

	return index;
}