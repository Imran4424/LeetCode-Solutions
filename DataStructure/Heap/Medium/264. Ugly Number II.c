
typedef long long int lli;

const lli heapSize = 2200;
const lli topIndex = 1;

lli myHeap[2201];
lli heapIndex;

void swapNode(lli source, lli destination) {
    lli temp = myHeap[source];

    myHeap[source] = myHeap[destination];
    myHeap[destination] = temp;
}

void bubbleUp(lli currentIndex) {
    lli parentIndex = currentIndex / 2;

    if(parentIndex < 1) {
        return;
    }

    if(myHeap[currentIndex] < myHeap[parentIndex]) {
        swapNode(currentIndex, parentIndex);

        bubbleUp(parentIndex);
    }
}

void heapInsert(lli val) {
    if(heapIndex >= heapSize) {
        return;
    }

    myHeap[++heapIndex] = val;

    bubbleUp(heapIndex);
}

void bubbleDown(lli currentIndex) {
    lli leftChild = currentIndex * 2;
    lli rightChild = currentIndex * 2 + 1;

    if(leftChild > heapIndex) {
        return;
    }

    if(rightChild > heapIndex && leftChild == heapIndex) {
        if(myHeap[leftChild] < myHeap[currentIndex]) {
            swapNode(currentIndex, leftChild);
        }

        return;
    }

    if(myHeap[leftChild] < myHeap[currentIndex]) {
        swapNode(currentIndex, leftChild);

        bubbleDown(leftChild);
    }

    if(myHeap[rightChild] < myHeap[currentIndex]) {
        swapNode(currentIndex, rightChild);

        bubbleDown(rightChild);
    }
}

lli deleteMinElement() {
    swapNode(heapIndex, topIndex);
    heapIndex--;
    bubbleDown(topIndex);

    return myHeap[heapIndex + 1];
}

/// hash code
typedef struct HashTable {
    lli data;
    struct HashTable *next;
} HashTable;

lli hashSize = 7777;

lli hashKey(lli number) {
    return number % hashSize;
}

/// hash Insert
HashTable* hashInsert(HashTable *head, lli val) {
    HashTable* temp = malloc(sizeof(HashTable));
    temp -> data = val;
    temp -> next = head;
    head = temp;

    return temp;
}

/// hashSearch
bool hashSearch(HashTable *head, lli val) {
    while(NULL != head) {
        if(head -> data == val) {
            return true;
        }

        head = head -> next;
    }

    return false;
}


lli nthUglyNumber(lli nTh) {
    heapIndex = 0;
    lli targetValue, count = 0;
    HashTable* hashHead[hashSize];

    for(lli i = 0; i < hashSize; i++) {
        hashHead[i] = NULL;
    }

    heapInsert(1);
    hashHead[1] = hashInsert(hashHead[1], 1);

    while(count < nTh) {
        targetValue = deleteMinElement();
        count++;

        lli valTwo = targetValue * 2;
        lli valThree = targetValue * 3;
        lli valFive =  targetValue * 5;

        lli keyTwo = hashKey(valTwo);
        lli keyThree = hashKey(valThree);
        lli keyFive = hashKey(valFive);


        if(!hashSearch(hashHead[keyTwo], valTwo)) {
            heapInsert(valTwo);
            hashHead[keyTwo] = hashInsert(hashHead[keyTwo], valTwo);
        }

        if(!hashSearch(hashHead[keyThree], valThree)) {
            heapInsert(valThree);
            hashHead[keyThree] = hashInsert(hashHead[keyThree], valThree);
        }

        if(!hashSearch(hashHead[keyFive], valFive)) {
            heapInsert(valFive);
            hashHead[keyFive] = hashInsert(hashHead[keyFive], valFive);
        }
    }

    return targetValue;
}
