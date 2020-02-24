

int findMaximumXOR(int* nums, int numsSize){
	int maxSum = 0;

	for (int i = 0; i < numsSize; i++) {
		for(int j = i + 1; j < numsSize; j++) {
			int sum =  nums[i] ^ nums[j];

			if(sum > maxSum) {
				maxSum = sum;
			}
		}
	}

	return maxSum;
}

