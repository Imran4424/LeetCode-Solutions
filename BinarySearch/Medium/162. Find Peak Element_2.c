


int findPeakElement(int* nums, int numsSize){
	int peakElemnet = nums[0];
	int peakIndex = 0;

	for (int i = 1; i < numsSize; i++) {
		if(i < numsSize - 1 && nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
			peakElemnet = nums[i];
			peakIndex = i;

			break;
		}

		if(peakElemnet < nums[i]) {
			peakElemnet = nums[i];
			peakIndex = i;
		}
	}

	return peakIndex;
}
