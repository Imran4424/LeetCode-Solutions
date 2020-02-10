/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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

bool binarySearch(int* nums, int numsSize, int target){
    int low = 0, high = numsSize - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(target > nums[mid]) {
            low = mid + 1;
        } else if(target < nums[mid]) {
            high = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}

int numComponents(struct ListNode* head, int* arr, int arrSize){

    if(NULL == head) {
        return 0;
    }

    if(NULL == head -> next) {
        return 1;
    }

    mergeSort(arr, arrSize);

    struct ListNode* travel = head;

    while(NULL != travel) {
        if(binarySearch(arr,arrSize, travel -> val)) {
            travel -> val = -999;
        }

        travel = travel -> next;
    }

    int num = 0;

    travel = head;

    while(NULL != travel) {
        if(-999 == travel -> val) {
            num++;

            while(NULL != travel && -999 == travel -> val) {
                travel = travel -> next;
            }
            
            continue;
        }

        travel = travel -> next;
    }

    return num;
}

