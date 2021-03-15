

void merge(int *arr, int *left, int leftSize, int *right, int rightSize) {
	int i = 0, j = 0, k = 0;

	while(i < leftSize && j < rightSize) {
		if (left[i] > right[j]) {
			arr[k++] = left[i++];
		} else {
			arr[k++] = right[j++];
		}
	}

	while (i < leftSize) {
		arr[k++] = left[i++];
	}

	while (j < rightSize) {
		arr[k++] = right[j++];
	}
}

void mergeSort(int *arr, int arrSize) {
	if (arrSize < 2) {
		return;
	}

	int mid = arrSize / 2;
	int left[mid];
	int right[arrSize - mid];

	int index = 0;

	for (int i = 0; i < mid; i++) {
		left[i] = arr[index++];
	}

	for (int i = 0; i < arrSize - mid; i++) {
		right[i] = arr[index++];
	}

	mergeSort(left, mid);
	mergeSort(right, arrSize - mid);

	merge(arr, left, mid, right, arrSize - mid);
}

int thirdMax(int* nums, int numsSize) {
	mergeSort(nums, numsSize);

	// remove duplicates
	int index = 1;
	for (int i = 1; i < numsSize; i++) {
		if(nums[i - 1] != nums[i]) {
			nums[index++] = nums[i];
		}
	}
	numsSize = index;

	if (numsSize < 3) {
		return nums[0];
	}

	return nums[2];
}