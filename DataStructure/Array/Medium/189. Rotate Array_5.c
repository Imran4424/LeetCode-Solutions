
void rotate(int* nums, int numsSize, int k){
	k = k % numsSize;

	int helperNums[numsSize];
	int count = 0;
	int placeIndex = 0;

	for (int i = 0; i < numsSize; i++) {
		if(count < k) {
			helperNums[count++] = nums[(i + k) % numsSize];
			nums[(i + k) % numsSize] = nums[i];
		} else {
			helperNums[count++] = nums[(i + k) % numsSize];
			nums[(i + k) % numsSize] = helperNums[placeIndex++];
		}
		
	}
}