/*

	Let's say nums looks like this: 
		[12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

	Because it's not fully sorted, we can't do normal binary search. But here comes the trick:

	    If target is let's say 14, then we adjust nums to this, where "inf" means infinity:
	    [12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]

	    If target is let's say 7, then we adjust nums to this:
	    [-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

*/

int search(int* nums, int numsSize, int target){
	if (0 == numsSize) {
		return -1;
	}

	int low = 0;
	int high = numsSize - 1;

	while(low < high) {
		int mid = low + (high - low) / 2;

		// target and mid on the same side
		if ((nums[mid] - nums[numsSize - 1]) * (target - nums[numsSize - 1]) > 0) {
			if (nums[mid] < target) {
				low = mid + 1;
			} else {
				high = mid + 1;
			}
		} else if (target > nums[numsSize - 1]) {
			// target on the left side
			high = mid + 1;
		} else {
			// target on the right side
			low = mid + 1;
		}
	}

	if(nums[low] == target) {
		return low;
	} else {
		return -1;
	}
}













