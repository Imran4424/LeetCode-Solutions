

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int indexOne, indexTwo;

    for(int i = 0; i < numbersSize; i++) {
        for(int j = i + 1; j < numbersSize; j++) {
            if(numbers[i] + numbers[j] == target) {
                indexOne = i + 1;
                indexTwo = j + 1;

                i = numbersSize;
                break;
            } else if(numbers[i] + numbers[j] > target) {
                break;
            }
        }
    }

    
    int *resultIndex = malloc(2 * sizeof(int));
    *returnSize = 2;
    
    resultIndex[0] = indexOne;
    resultIndex[1] = indexTwo;

    return resultIndex;
}