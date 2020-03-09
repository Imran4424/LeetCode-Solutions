

bool uniqueOccurrences(int* arr, int arrSize){
    int occurCount[2002] = {0};

    for(int i = 0; i < arrSize; i++) {
        occurCount[arr[i] + 1000]++;
    }

    int frequencyCount[1001] = {0};

    for(int i =0; i < 2002 - 1; i++) {
        if(0 == occurCount[i]) {
            continue;
        }

        frequencyCount[occurCount[i]]++;

        if(2 <= frequencyCount[occurCount[i]]) {
            return false;
        }
    }

    return true;
}

