
int findMin(int* nums, int numsSize) {
	int minValue = nums[numsSize - 1];

	for(int i = numsSize - 1; i >= 0; i--) {
		if(nums[i] < minValue) {
			minValue = nums[i];
		} else if (nums[i] > minValue) {
			break;
		}
	}

	return minValue;
}














