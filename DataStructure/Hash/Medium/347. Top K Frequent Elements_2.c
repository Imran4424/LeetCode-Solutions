
const int hashSize = 1000;

typedef struct HashTable 
{
        int number;
        int frequency;
        struct HashTable *next;
} HashTable;

int Absolute(int x) {
        if(x < 0) {
                return -x;
        }

        return x;
}

int hashKey(int number) {
        return Absolute(number) % hashSize;
}

void initHash(HashTable** head) {
        for(int i = 0; i < hashSize; i++) {
                head[i] = NULL;
        }
}

HashTable* createNode(int num) {
        HashTable* temp = malloc(sizeof(HashTable));
        temp -> number = num;
        temp -> frequency = 1;
        temp -> next = NULL;

        return temp;
}

HashTable* insertHash(HashTable* head, int num) {
        if(NULL == head) {
                head = createNode(num);

                return head;
        }
        
        HashTable *travel = head;
        HashTable *previos = NULL;

        while(NULL != travel) {
                if(num == travel -> number) {
                        travel -> frequency++;
                        return head;
                }
                
                previos = travel;
                travel = travel -> next;
        }

        previos -> next = createNode(num);
        return head;
}

const int heapSize = 2001;
const int top = 1;
HashTable* myHeap[2001 + 1];
int heapIndex;

void swapNode(int source, int destination) {
        HashTable* temp = myHeap[source];
        myHeap[source] = myHeap[destination];
        myHeap[destination] = temp;
}

void bubbleUp(int currentIndex) {
        int parentIndex = currentIndex / 2;

        if(parentIndex < 1) {
                return;
        }

        if(myHeap[currentIndex] -> frequency > myHeap[parentIndex] -> frequency) {
                swapNode(currentIndex, parentIndex);

                bubbleUp(parentIndex);
        }
}

void insertHeap(HashTable *node) {
        if(heapIndex >= heapSize) {
                return;
        }

        myHeap[++heapIndex] = node;
        

        bubbleUp(heapIndex);
}

void bubbleDown(int currentIndex) {
        int leftChild = currentIndex * 2;
        int rightChild = currentIndex * 2 + 1;

        if(leftChild > heapIndex) {
                return;
        }

        if(rightChild > heapIndex && leftChild <= heapIndex) {
                if(myHeap[leftChild] -> frequency > myHeap[currentIndex] -> frequency) {
                        swapNode(currentIndex, leftChild);
                }      

                return;
        }

        if(myHeap[leftChild] -> frequency > myHeap[currentIndex] -> frequency && myHeap[rightChild] -> frequency > myHeap[currentIndex] -> frequency) {
                if(myHeap[leftChild] -> frequency > myHeap[rightChild] -> frequency) {
                        swapNode(currentIndex, leftChild);

                        bubbleDown(leftChild);
                } else {
                        swapNode(currentIndex, rightChild);

                        bubbleDown(rightChild);
                }
        } else if(myHeap[leftChild] -> frequency > myHeap[currentIndex] -> frequency) {
                swapNode(currentIndex, leftChild);

                bubbleDown(leftChild);
        } else if(myHeap[rightChild] -> frequency > myHeap[currentIndex] -> frequency){
                swapNode(currentIndex, rightChild);

                bubbleDown(rightChild);
        }
}

HashTable* deleteMaxElement() {
        if(heapIndex < 1) {
                return NULL;
        }

        swapNode(heapIndex, top);
        heapIndex--;
        bubbleDown(top);

        return myHeap[heapIndex + 1];
}

void heapBuilder(HashTable* travel) {
        while(NULL != travel) {
                insertHeap(travel);
                travel = travel -> next;
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
        //initialization
        heapIndex = 0;
        HashTable *head[hashSize];
        initHash(head);

        for(int i = 0; i < numsSize; i++) {
                int key = hashKey(nums[i]);
                head[key] = insertHash(head[key], nums[i]);
        }

        for(int i = 0; i < hashSize; i++) {
                heapBuilder(head[i]);
        }

        int* topElement = malloc(k * sizeof(int));

        for(int i = 0; i < k; i++) {
                HashTable* maxNode = deleteMaxElement();
                topElement[i] = maxNode -> number;
        }

        *returnSize = k;
        return topElement;
}

