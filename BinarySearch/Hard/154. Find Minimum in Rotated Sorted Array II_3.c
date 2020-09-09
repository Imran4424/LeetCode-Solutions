/*
	4 5 6 7 2 3

	infection point 7 2
	left of infection point 7
	right of infection point 2
	
	first element of array 4

	left of infection point > first element = 7 > 4
	right of infection point < first element = 2 < 4
*/


int findMin(int* nums, int numsSize) {
	int low = 0;
	int high = numsSize - 1;

	if (nums[low] < nums[high] || numsSize < 2) {
		return nums[low];
	}

	while(low <= high) {
		int mid = low + (high - low) / 2;

		if (nums[mid] > nums[mid + 1]) {
			return nums[mid + 1];
		} else if (nums[mid] < nums[mid - 1]) {
			return nums[mid];
		} else if (nums[mid] > nums[0]) {
		      	/*
				if the mid elements value is greater than the 0th element this means
				the least value is still somewhere to the right as we are still 
				dealing with elements	
		      	*/

			low = mid + 1;
		} else if (nums[mid] < nums[0]) {
			/*
				if nums[0] is greater than the mid value then this means the smallest 
				value is somewhere to the left
			*/
			high = mid - 1;
		}
	}

	return nums[0];
}