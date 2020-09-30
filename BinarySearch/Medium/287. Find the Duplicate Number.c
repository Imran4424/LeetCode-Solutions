


int findDuplicate(int* nums, int numsSize) {
	int vistied[30001];

	for(int i = 0; i < numsSize; i++) {
		if(nums[i] == vistied[nums[i]]) {
			return nums[i];
		} else {
			vistied[nums[i]] = nums[i];
		}
	}

	return nums[0];    
}