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

	while(low <= high) {
		int mid = low + (high - low) / 2;

	}
}
