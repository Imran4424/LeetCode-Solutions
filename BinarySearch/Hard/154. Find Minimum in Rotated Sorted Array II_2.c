



int findMin(int* nums, int numsSize){
    int min = nums[0];

    for(int i = numsSize - 1; i > 0; i--) {
        if(nums[i - 1] > nums[i]) {
            return nums[i];
        }
    }

    return min;
}


