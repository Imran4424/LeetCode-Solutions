/// Using Max Heap


const int hashSize = 1000;

typedef struct HashTable {
        char word[20];
        int frequency;
        struct HashTable *next;
} HashTable;

int hashKey(char * word) {
        long long int asciiNum = 0;

        for (int i = 0; word[i]; i++) {
                asciiNum = (asciiNum * 10) + word[i];
        }

        return asciiNum % hashSize;
}

void copyString(char *destination, char *source) {
        int i;
        for(i = 0; source[i]; i++) {
                destination[i] = source[i];
        }

        destination[i] = '\0';
}

int compareString(char *subject, char *comparedWord) {
        int i;
        for(i = 0; subject[i]; i++) {
                if(subject[i] != comparedWord[i]) {
                        return subject[i] - comparedWord[i];
                }
        }

        return subject[i] - comparedWord[i];
}

HashTable* createHashNode(char *word) {
        HashTable* temp = malloc(sizeof(HashTable));
        copyString(temp -> word, word);
        temp -> frequency = 1;
        temp -> next = NULL;

        return temp;
}

HashTable* insertHash(HashTable *head, char *word) {
        if(NULL == head) {
                return createHashNode(word);
        }

        HashTable* travel = head;
        HashTable* previous = NULL;

        while(NULL != travel) {
                if(0 == compareString(travel -> word, word)) {
                        travel -> frequency++;
                        return head;
                }

                previous = travel;
                travel = travel -> next;
        }

        previous -> next = createHashNode(word);
        return head;
}

void initHash(HashTable** head) {
        for(int i = 0; i < hashSize; i++) {
                head[i] = NULL;
        }
}

typedef struct {
        char word[20];
        int frequency;
} HeapNode;

const int heapSize = 1000;
const int topIndex = 1;
HeapNode myHeap[1000 + 1];
int heapIndex;

HeapNode createHeapNode(HashTable *node) {
        HeapNode temp;
        copyString(temp.word, node -> word);
        temp.frequency = node -> frequency;
        return temp;
}

void swapNode(int source, int destination) {
        HeapNode temp = myHeap[source];
        myHeap[source] = myHeap[destination];
        myHeap[destination] = temp;
}

void bubbleUp(int currentIndex) {
        int parentIndex = currentIndex / 2;

        if(parentIndex < topIndex) {
                return;
        }

        if(myHeap[currentIndex].frequency > myHeap[parentIndex].frequency) {
                swapNode(currentIndex, parentIndex);

                bubbleUp(parentIndex);
        } else if (myHeap[currentIndex].frequency == myHeap[parentIndex].frequency) {
                if (compareString(myHeap[currentIndex].word, myHeap[parentIndex].word) < 0) {
                        swapNode(currentIndex, parentIndex);

                        bubbleUp(parentIndex);
                }
        }
}

void insertHeap(HeapNode node) {
        if(heapIndex >= heapSize) {
                return;
        }

        myHeap[++heapIndex] = node;

        bubbleUp(heapIndex);
}

void bubbleDown(int currentIndex) {
        if (currentIndex >= heapIndex) {
                return;
        }

        int leftChild = currentIndex * 2;
        int rightChild = currentIndex * 2 + 1;

        int biggest = currentIndex;

        if (leftChild <= heapIndex) {
                if (myHeap[leftChild].frequency > myHeap[biggest].frequency) {
                        biggest = leftChild;
                } else if (myHeap[leftChild].frequency == myHeap[biggest].frequency) {
                        if (compareString(myHeap[leftChild].word, myHeap[biggest].word) < 0) {
                                biggest = leftChild;
                        }
                }
        }

        if (rightChild <= heapIndex) {
                if (myHeap[rightChild].frequency > myHeap[biggest].frequency) {
                        biggest = rightChild;
                } else if (myHeap[rightChild].frequency == myHeap[biggest].frequency) {
                        if (compareString(myHeap[rightChild].word, myHeap[biggest].word) < 0) {
                                biggest = rightChild;
                        }
                }
        }

        if (biggest != currentIndex) {
                swapNode(currentIndex, biggest);
                bubbleDown(biggest);
        }       
}

HeapNode deleteMaxElement() {
        if(heapIndex < topIndex) {
                return;
        }

        swapNode(topIndex, heapIndex);
        heapIndex--;

        bubbleDown(topIndex);

        return myHeap[heapIndex + 1];
}

void populateHeap(HashTable* travel) {
        while (NULL != travel) {
                insertHeap(createHeapNode(travel));

                travel = travel -> next;
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize) {
        HashTable* head[hashSize];
        initHash(head);
        int key;
        for(int i = 0; i < wordsSize; i++) {
                key = hashKey(words[i]);
                head[key] = insertHash(head[key], words[i]);
        }

        heapIndex = 0;

        for(int i = 0; i < hashSize; i++) {
                if(NULL != head[i]) {
                        populateHeap(head[i]);
                }
        }

        char** frequentWords = malloc(k * sizeof(char *));
        for(int i = 0; i < k; i++) {
                frequentWords[i] = malloc(20 * sizeof(char));
        }

        for(int i = 0; i < k; i++) {
                copyString(frequentWords[i], deleteMaxElement().word);
        }

        *returnSize = k;
        return frequentWords;
}

