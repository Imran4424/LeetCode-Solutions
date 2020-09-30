


int findDuplicate(int* nums, int numsSize) {
	int vistied[30001] = {0};

	for(int i = 0; i < numsSize; i++) {
		if(vistied[nums[i]]) {
			return nums[i];
		}
	}    
}