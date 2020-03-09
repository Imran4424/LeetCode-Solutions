

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *smallCount = malloc(numsSize * sizeof(int));

    /// frequency count hash
    int hashCount[101] = {0};

    /// calculating hash frequency
    for(int i = 0; i < numsSize; i++) {
        hashCount[nums[i]]++;
    }

    /// calculating total frequency at position from number 0 to number i
    for(int i = 1; i < 101; i++) {
        hashCount[i] += hashCount[i - 1];
    }

    /// placing i-1 frequency for i position, for finding count of lesser values than i
    for(int i = 0; i < numsSize; i++) {
        if(0 == nums[i]) {
            smallCount[i] = 0;
        } else {
            smallCount[i] = hashCount[nums[i] - 1];
        }
    }

    *returnSize = numsSize;
    return smallCount;
}

