

typedef struct DistanceList {
    int pointX, pointY;
    int distance;
} DistanceList;


void merge(DistanceList *arr, DistanceList  *left, int leftSize, DistanceList *right, int rightSize) {
    int i = 0, j = 0, index = 0;

    while(i < leftSize && j < rightSize) {
        if(left[i].distance < right[j].distance) {
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

void mergeSort(DistanceList *arr, int aSize) {
    if(aSize < 2) {
        return;
    }

    int mid = aSize / 2;
    DistanceList left[mid];
    DistanceList right[aSize - mid];

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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){

}

