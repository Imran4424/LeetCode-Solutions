typedef struct {
    int count;
    char ch;
} charCount;

void merge(charCount *arr, charCount *left, int leftSize, charCount *right, int rightSize) {
    int i = 0, j = 0, index = 0;

    while(i < leftSize && j < rightSize) {
        if(left[i].count > right[j].count) {
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

void mergeSort(charCount *arr, int aSize) {
    if(aSize < 2) {
        return;
    }

    int mid = aSize / 2;
    charCount left[mid];
    charCount right[aSize - mid];

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

void init(charCount *sCount) {
    for(int i = 0; i < 26; i++) {
        sCount[i].count = 0;
        sCount[i].ch = 'a' + i;
    }
}


char * reorganizeString(char * str){
    charCount sCount[26];
    init(sCount);
    int i;
    for(i = 0; str[i]; i++) {
        sCount[str[i] - 'a'].count++;
    }

    int length = i;

    char *sortedStr = malloc((length + 1) * sizeof(char));

    int index;

    char last = '.';

    for(index = 0; index < length; index++) {
        /// finding max
        mergeSort(sCount, 26);
        int current = 0;

        /// founding next char different from previous
        while (index > 0 && sCount[current].ch == last) {
            current++;
        }
        
        /// if not possible
        if(0 == sCount[current].count) {
            return "";
        }

        sortedStr[index] = sCount[current].ch;
        sCount[current].count--;
        last = sortedStr[index];

     
    }

    sortedStr[index] = '\0';

    return sortedStr;
}
