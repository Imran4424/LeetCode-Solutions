
int thirdMax(int* nums, int numsSize){
	long long int maxOne = LONG_MIN;
	long long int maxTwo = LONG_MIN;
	long long int maxThree = LONG_MIN;

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == maxOne || nums[i] == maxTwo || nums[i] == maxThree) {
			continue;
		}

		if (nums[i] > maxOne) {
			maxThree = maxTwo;
			maxTwo = maxOne;
			maxOne = nums[i];
		} else if (nums[i] > maxTwo && nums[i] < maxOne) {
			maxThree = maxTwo;
			maxTwo = nums[i];
		} else if (nums[i] > maxThree && nums[i] < maxTwo) {
			maxThree = nums[i];
		}
	}

	if (maxThree == LONG_MIN) {
		return maxOne;
	}

	return maxThree;
}