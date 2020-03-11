


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

bool binarySearch(int *arr, int aSize, int target) {
    int low = 0;
    int high = aSize - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(target > arr[mid]) {
            low = mid + 1;
        } else if(target < arr[mid]) {
            high = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    mergeSort(nums1, nums1Size);
    mergeSort(nums2, nums2Size);

    int *sectArr;

    sectArr = malloc(nums1Size * sizeof(int));

    int index = 0;

    for(int i = 0; i < nums2Size; i++) {
        if(i > 0 && nums2[i - 1] == nums2[i]) {
            continue;
        }

        if(binarySearch(nums1, nums1Size, nums2[i])) {
            sectArr[index++] = nums2[i];
        }
    }

    *returnSize = index;

    return sectArr;
}
