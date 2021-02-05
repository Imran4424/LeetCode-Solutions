/**
	https://www.cs.utexas.edu/~moore/best-ideas/mjrty/example.html

	A Linear Time Majority Vote Algorithm
*/


int majorityElement(int* nums, int numsSize){
	int majorElement = nums[0];
	int count = 1;

	for (int i = 1; i < numsSize; i++) {
		if (0 == count) {
			majorElement = nums[i];
			count = 1;
		} else if (majorElement == nums[i]) {
			count++;
		} else {
			count--;
		}
	}

	return majorElement;
}