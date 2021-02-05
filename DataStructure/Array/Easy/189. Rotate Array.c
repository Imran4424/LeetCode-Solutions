
void rotateRightToLeft(int* nums, int numsSize) {
	int store = nums[numsSize - 1];

	for (int i = 1; i < numsSize; i++) {
		nums[i] = nums[i - 1];
	}

	nums[0] = store;
}

void rotate(int* nums, int numsSize, int k){
	while(k--) {
		rotateRightToLeft(nums, numsSize);
	}
}