

void merge(int *left, int leftSize, int *right, int rightSize, int *arr) {
	int i = 0, j = 0, k = 0;

	while (i < leftSize && j < rightSize) {
		if (left[i] <= right[j]) {
			arr[k] = left[i++];
		} else {
			arr[k] = right[j++];
		}

		k++;
	}

	while(i < leftSize) {
		arr[k++] = left[i++];
	}

	while(j < rightSize) {
		arr[k++] = right[j++];
	}
}

void mergeSort(int *arr, int size) {
	if (size < 2) {
		return;
	}

	int mid = size / 2;
	int left[mid];
	int right[size - mid];

	for (int i = 0; i < mid; i++) {
		left[i] = arr[i];
	}

	for (int i = mid; i < size; i++) {
		right[i - mid] = arr[i]; 
	}

	mergeSort(left, mid);
	mergeSort(right, size - mid);

	merge(left, mid, right, size - mid, arr);
}

int findDuplicate(int* nums, int numsSize){
	mergeSort(nums, numsSize);

	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i - 1]) {
			return nums[i];
		}
	}

	return -1;
}