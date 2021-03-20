/**
	Logic learned from this code

	appeared positions value will be negative
	not appreared positions value will be positive
*/

int Absolute(int x) {
	if (x < 0) {
		return -x;
	}

	return x;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	for (int i = 0; i < numsSize; i++) {
		int temp = nums[i];

		if (temp < 0) {
			temp = -temp;
		}

		if (nums[temp - 1] > 0) {
			nums[temp - 1] = -nums[temp - 1];
		}
	}

	int *disArr = malloc(numsSize * sizeof(int));
	int index = 0;

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > 0) {
			disArr[index++] = i + 1;
		}
	}

	*returnSize = index;
	return disArr;
}