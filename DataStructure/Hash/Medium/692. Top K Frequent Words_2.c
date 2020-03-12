
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

int heapSize;
const int topIndex = 1;
HeapNode *myHeap;
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

        if(myHeap[currentIndex].frequency < myHeap[parentIndex].frequency) {
                swapNode(currentIndex, parentIndex);

                bubbleUp(parentIndex);
        } else if (myHeap[currentIndex].frequency == myHeap[parentIndex].frequency) {
                if (compareString(myHeap[currentIndex].word, myHeap[parentIndex].word) > 0) {
                        swapNode(currentIndex, parentIndex);

                        bubbleUp(parentIndex);
                }
        }
}

void bubbleDown(int currentIndex) {
        int leftChild = currentIndex * 2;
        int rightChild = currentIndex * 2 + 1;

        if(leftChild > heapIndex) {
                return;
        }

        if(rightChild > heapIndex && leftChild <= heapIndex) {
                if(myHeap[leftChild].frequency < myHeap[currentIndex].frequency) {
                        swapNode(currentIndex, leftChild);
                } else if(myHeap[leftChild].frequency == myHeap[currentIndex].frequency) {
                        if(compareString(myHeap[leftChild].word, myHeap[currentIndex].word) > 0) {
                                swapNode(currentIndex, leftChild);
                        }
                }

                return;
        }

        if(myHeap[leftChild].frequency < myHeap[currentIndex].frequency) {
                swapNode(currentIndex, leftChild);

                bubbleDown(leftChild);
        } else if(myHeap[leftChild].frequency == myHeap[currentIndex].frequency) {
                if(compareString(myHeap[leftChild].word, myHeap[currentIndex].word) > 0) {
                        swapNode(currentIndex, leftChild);

                        bubbleDown(leftChild);
                }
        }

        if(myHeap[rightChild].frequency < myHeap[currentIndex].frequency) {
                swapNode(currentIndex, rightChild);

                bubbleDown(rightChild);
        } else if(myHeap[rightChild].frequency == myHeap[currentIndex].frequency) {
                if(compareString(myHeap[rightChild].word, myHeap[currentIndex].word) > 0) {
                        swapNode(currentIndex, rightChild);

                        bubbleDown(rightChild);
                }
        }
}

HeapNode deleteMinElement() {
        if(heapIndex < topIndex) {
                return myHeap[0];
        }

        swapNode(topIndex, heapIndex);
        heapIndex--;

        bubbleDown(topIndex);

        return myHeap[heapIndex + 1];
}

void insertHeap(HeapNode node) {
        if(heapIndex >= heapSize) {
                if(myHeap[topIndex].frequency < node.frequency) {
                    deleteMinElement();
                } else if(myHeap[topIndex].frequency == node.frequency) {
                    if(compareString(myHeap[topIndex].word, node.word) > 0) {
                        deleteMinElement();
                    } else {
                        return;
                    }

                } else {
                    return;
                }
        }

        myHeap[++heapIndex] = node;

        bubbleUp(heapIndex);
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

        heapSize = k;
        myHeap = malloc((k + 1) * sizeof(HeapNode));
        heapIndex = 0;
        myHeap[0] = createHeapNode(createHashNode("dummy"));

        for(int i = 0; i < hashSize; i++) {
                if(NULL != head[i]) {
                        populateHeap(head[i]);
                }
        }

        char** frequentWords = malloc(k * sizeof(char *));
        for(int i = 0; i < k; i++) {
                frequentWords[i] = malloc(20 * sizeof(char));
        }

        for(int i = k - 1; i >= 0; i--) {
                copyString(frequentWords[i], deleteMinElement().word);
        }

        *returnSize = k;
        return frequentWords;
}

