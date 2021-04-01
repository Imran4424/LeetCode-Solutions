typedef struct FrequencyList {
    char value;
    int freq;
} FrequencyList;

const int listSize = 256;

void merge(FrequencyList *arr, FrequencyList  *left, int leftSize, FrequencyList *right, int rightSize) {
    int i = 0, j = 0, index = 0;

    while(i < leftSize && j < rightSize) {
        if(left[i].freq > right[j].freq) {
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

void mergeSort(FrequencyList *arr, int aSize) {
    if(aSize < 2) {
        return;
    }

    int mid = aSize / 2;
    FrequencyList left[mid];
    FrequencyList right[aSize - mid];

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

char * frequencySort(char * word){
    FrequencyList myCharfreq[listSize];

    for(int i = 0; i < listSize; i++) {
        myCharfreq[i].freq = 0;
    }

    for(int i = 0; word[i]; i++) {
        int index = (int) word[i];

        myCharfreq[index].value = word[i];
        myCharfreq[index].freq++;
    }

    mergeSort(myCharfreq, listSize);

    int index = 0;

    for(int i = 0; i < listSize; i++) {
        while(myCharfreq[i].freq--) {
            word[index++] = myCharfreq[i].value;
        }
    }

    return word;
}

