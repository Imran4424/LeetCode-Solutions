
void rotate(int* nums, int numsSize, int k){
	int helperNums[numsSize];

	for (int i = 0; i < numsSize; i++) {
		helperNums[(i + k) % numsSize] = nums[i];
	}

	for(int i = 0; i < numsSize; i++) {
		nums[i] = helperNums[i];
	}
}