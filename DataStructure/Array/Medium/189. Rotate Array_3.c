
void rotate(int* nums, int numsSize, int k){
	if(0 == k) {
		return;
	}

	int store = nums[numsSize - 1];

	for (int i = numsSize - 1; i > 0; i--) {
		nums[i] = nums[i - 1];
	}

	nums[0] = store;

	rotate(nums, numsSize, k-1);
}