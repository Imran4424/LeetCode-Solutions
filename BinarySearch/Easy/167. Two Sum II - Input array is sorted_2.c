

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int indexOne, indexTwo;

    for(int first = 0; first < numbersSize; first++) {
        int low = first + 1;
        int high = numbersSize - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(target > numbers[first] + numbers[mid]) {
                low = mid + 1;
            } else if(target < numbers[first] + numbers[mid]) {
                high = mid - 1;
            } else {
                indexOne = first + 1;
                indexTwo = mid + 1;

                first = numbersSize;
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

