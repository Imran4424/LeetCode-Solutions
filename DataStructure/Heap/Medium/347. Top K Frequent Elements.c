typedef struct FrequencyList {
    int value;
    int freq;
} FrequencyList;


void mergeFrequency(FrequencyList *arr, FrequencyList  *left, int leftSize, FrequencyList *right, int rightSize) {
    int i = 0, j = 0, index = 0;

    while(i < leftSize && j < rightSize) {
        if(left[i].freq > right[j].freq) {
            arr[index] = left[i++];
        } else {
            arr[index] = right[j++];
        }

        index++;
    }

    while(i < leftSize) {
        arr[index++] = left[i++];
    }

    while(j < rightSize) {
        arr[index++] = right[j++];
    }
}

void mergeSortFrequency(FrequencyList *arr, int aSize) {
    if(aSize < 2) {
        return;
    }

    int mid = aSize / 2;
    FrequencyList left[mid];
    FrequencyList right[aSize - mid];

    int index = 0;

    for(int i = 0; i < mid; i++) {
        left[i] = arr[index++];
    }

    for(int i = 0; i < aSize - mid; i++) {
        right[i] = arr[index++];
    }

    mergeSortFrequency(left, mid);
    mergeSortFrequency(right, aSize - mid);

    mergeFrequency(arr, left, mid, right, aSize - mid);
}

void merge(int *arr, int *left, int leftSize, int *right, int rightSize) {
    int i = 0, j = 0, index = 0;

    while(i < leftSize && j < rightSize) {
        if(left[i] < right[j]) {
            arr[index] = left[i++];
        } else {
            arr[index] = right[j++];
        }

        index++;
    }

    while(i < leftSize) {
        arr[index++] = left[i++];
    }

    while(j < rightSize) {
        arr[index++] = right[j++];
    }
}

void mergeSort(int *arr, int aSize) {
    if(aSize < 2) {
        return;
    }

    int mid = aSize / 2;
    int left[mid];
    int right[aSize - mid];

    int index = 0;

    for(int i = 0; i < mid; i++) {
        left[i] = arr[index++];
    }

    for(int i = 0; i < aSize - mid; i++) {
        right[i] = arr[index++];
    }

    mergeSort(left, mid);
    mergeSort(right, aSize - mid);

    merge(arr, left, mid, right, aSize - mid);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
	mergeSort(nums, numsSize);
	FrequencyList myFrequencyList[numsSize];

	for(int i = 0; i < numsSize; i++) {
		myFrequencyList[i].freq = 0;
	}

	int index = 0;

	for(int i = 0; i < numsSize; i++) {
		myFrequencyList[index].value = nums[i];
		myFrequencyList[index].freq++;

		while(i < numsSize - 1 && nums[i] == nums[i + 1]) {
			myFrequencyList[index].freq++;
			i++;
		}

		index++;
	}

	mergeSortFrequency(myFrequencyList, index);
	int *result = malloc(k * sizeof(int));

	for(int i = 0; i < k; i++) {
		result[i] = myFrequencyList[i].value;
	}

	*returnSize = k;
	return result;
}

