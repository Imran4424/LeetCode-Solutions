


int findPeakElement(int* nums, int numsSize){
	
	for (int i = 1; i < numsSize; i++) {
		if(nums[i - 1] > nums[i]) {
			return i - 1;
		}
	}
	
	return numsSize - 1;
}



