
/*
	simulations
	1 2 3 1
	low = 0, high = 3, mid = 0 + (3 - 0)/2 = 1
	low = mid + 1 = 1 + 1 = 2, high = 3, mid = 2 + (3 - 2) / 2 = 2
	low = 2 + 1 = 3, high = 3
	while condition false
	break

	1 2
	low = 0, high = 1, mid = 0 + (1 - 0)/2 = 0
	low = 0 + 1 = 1, high = 1
	while condition false
	break

	1 2 1 2 1 3 1


*/


int findPeakElement(int* nums, int numsSize){
	
	if(0 == numsSize) {
		return 0;
	}

	int low = 0;
	int high = numsSize - 1;

	while(low < high) {
		int mid = low + (high - low) / 2;

		if (nums[mid] > nums[mid + 1]) {
			high = mid;
		} else if (nums[mid] < nums[mid + 1]) {
			low = mid + 1;
		}
	}
	
	return low;
}

