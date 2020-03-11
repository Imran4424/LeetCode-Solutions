
// Bitwise Operation

int singleNumber(int* nums, int numsSize) {
    if(0 == numsSize) {
        return 0;
    }
    
    int aloneNum = nums[0];
    
    for(int i = 1; i < numsSize; i++) {
        aloneNum = aloneNum ^ nums[i];
    }

    return aloneNum;
}

