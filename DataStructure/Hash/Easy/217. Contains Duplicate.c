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

bool containsDuplicate(int* nums, int numsSize){
    mergeSort(nums, numsSize);

    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[i+1]) {
            return true;
        }
    }

    return false;
}
