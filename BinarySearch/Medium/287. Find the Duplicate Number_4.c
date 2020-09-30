

void merge(int *left, int leftSize, int *right, int rightSize, int *arr) {
	int i = 0, j = 0, k = 0;

	while ()
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