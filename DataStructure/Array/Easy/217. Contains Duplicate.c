
void merge(int *arr, int arrSize, int *left, int leftSize, int *right, int rightSize) {
	int i = 0, j = 0, k = 0;

	while(i < leftSize && j < rightSize) {
		if(left[i] < right[j]) {
			arr[k++] = left[i++];
		} else {
			arr[k++] = right[j++];
		}
	}

	while(i < leftSize) {
		arr[k++] = left[i++];
	}

	while(j < rightSize) {
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

	for(int i = 0; i < mid; i++) {
		left[i] = arr[i];
	}

	for(int i = 0; i < arrSize - mid; i++) {
		right[i] = arr[arrSize - mid + i];
	}

	merge(arr, arrSize, left, mid, right, arrSize - mid);
}

bool containsDuplicate(int* nums, int numsSize){
	mergeSort(nums, numsSize);

	for (int i = 0; i < numsSize - 1; i++) {
		if(nums[i] == nums[i + 1]) {
			return true;
		}
	}

	return false;
}