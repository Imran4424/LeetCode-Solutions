

int removeElement(int* nums, int numsSize, int val){
	if (0 == numsSize) {
		return numsSize;
	}

	int index = 0;
	
	for (int i = 0; i < numsSize; i++) {
		if(val == nums[i]) {
			continue;
		}

		nums[index++] = nums[i];
	}

	return index;
}