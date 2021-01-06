

int searchInsert(int* nums, int numsSize, int target){
    int low = 0;
    int high = numsSize - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        //printf("%d %d %d\n", low, high, mid);

        if(target > nums[mid]) {
            low = mid + 1;
        } else if(target < nums[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }

        //printf("%d %d %d\n", low, high, mid);
    }

    return low;
}

