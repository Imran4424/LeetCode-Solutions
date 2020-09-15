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

	// 1 size array
	if (1 == numsSize) {
		return nums[0];
	}

	// 2 size array
	if (numsSize < 3) {
		if(nums[0] < nums[1]) {
			return nums[0]; 
		} 

		return nums[1];
	}

	//if not rotated
	if (nums[low] < nums[high]) {
		return nums[low];
	}

	while(low < high) {
		int mid = low + (high - low) / 2;

		if (nums[mid] > nums[mid + 1]) {
			return nums[mid + 1];
		} else if (nums[mid] < nums[mid - 1]) {
			return nums[mid];
		} else if (nums[mid] > nums[low]) {
		      	/*
				if the mid elements value is greater than or equal the low element this means
				the least value is still somewhere to the right as we are still 
				dealing with elements	
		      	*/

			low = mid + 1;
		} else if (nums[mid] < nums[high]) {
			/*
				if high is greater than or equal to the mid value then this means the smallest 
				value is somewhere to the left
			*/
			
			high = mid - 1;
		}

		while (low < numsSize - 1 && nums[low + 1] >= nums[low]) {
			low++;
		}

		while (high > 0 && nums[high - 1] <= nums[high]) {
			high--;
		}

	}

	if (nums[low] < nums[0]) {
		return nums[low];
	}

	return nums[0];
}