


int findDuplicate(int* nums, int numsSize) {
	bool vistied[30001] = {0};

	for(int i = 0; i < numsSize; i++) {
		if(vistied[nums[i]]) {
			return nums[i];
		} else {
			vistied[nums[i]] = true;
		}
	}

	return nums[0];    
}