



int findMin(int* nums, int numsSize){
    int min = nums[0];

    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] > nums[i + 1]) {
            return nums[i+1];
        }
    }

    return min;
}


