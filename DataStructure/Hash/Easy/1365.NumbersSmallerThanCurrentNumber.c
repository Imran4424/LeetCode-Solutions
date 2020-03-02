

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *smallCount = malloc(numsSize * sizeof(int));

    for(int i = 0; i < numsSize; i++) {
        smallCount[i] = 0;

        for(int j = 0; j < numsSize; j++) {
            if(i != j && nums[i] > nums[j]) {
                smallCount[i]++;
            }
        }
    }

    *returnSize = numsSize;
    return smallCount;
}

