


int findDuplicate(int* nums, int numsSize) {
	int vistied[30001];

	for(int i = 0; i < numsSize; i++) {
		if(vistied[nums[i]]) {
			return nums[i];
		} else {
			vistied[nums[i]] = 1;
		}
	}

	return nums[0];    
}