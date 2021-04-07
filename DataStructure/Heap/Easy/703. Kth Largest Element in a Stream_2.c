
const int heapSize = 100700;
const int topIndex = 1;

int myHeap[100701];

typedef struct {
    int heapIndex;
    int k;
} KthLargest;

void swapNode(int source, int destination) {
    int temp = myHeap[source];

    myHeap[source] = myHeap[destination];
    myHeap[destination] = temp;
}

void bubbleDown(KthLargest *obj, int currentIndex) {
    if(currentIndex >= obj -> heapIndex) {
        return;
    }

    int leftChild = currentIndex * 2;
    int rightChild = currentIndex * 2 + 1;

    int smallest = currentIndex;

    if(leftChild <= obj -> heapIndex && myHeap[leftChild] < myHeap[smallest]) {
        smallest = leftChild;
    }

    if(rightChild <= obj -> heapIndex && myHeap[rightChild] < myHeap[smallest]) {
        smallest = rightChild;
    }

    if (currentIndex != smallest) {
        swapNode(currentIndex, smallest);
        bubbleDown(obj, smallest);
    }
}

int deleteMinElement(KthLargest *obj) {
    swapNode(topIndex, obj -> heapIndex);
    obj -> heapIndex--;

    bubbleDown(obj, topIndex);

    return myHeap[obj -> heapIndex + 1];
}


void bubbleUp(int currentIndex) {
    int parentIndex = currentIndex / 2;

    if(parentIndex < 1) {
        return;
    }

    if(myHeap[currentIndex] < myHeap[parentIndex]) {
        swapNode(currentIndex, parentIndex);

        bubbleUp(parentIndex);
    }
}

void insertHeap(KthLargest *obj, int data) {
    if(obj -> heapIndex >= obj -> k) {
        if(myHeap[topIndex] > data) {
            return;
        }

        deleteMinElement(obj);
    }

    obj -> heapIndex++;
    myHeap[obj -> heapIndex] = data;

    bubbleUp(obj -> heapIndex);
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = malloc(sizeof(KthLargest));
    obj -> heapIndex = 0;
    obj -> k = k;

    for(int i = 0; i < numsSize; i++) {
        insertHeap(obj, nums[i]);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    insertHeap(obj, val);

    return myHeap[topIndex];
}

void kthLargestFree(KthLargest* obj) {
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/
