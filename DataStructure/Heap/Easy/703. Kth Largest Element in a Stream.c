
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

void bubbleDown(KthLargest *obj, int currentIndex) {
    int leftChild = currentIndex * 2;
    int rightChild = currentIndex * 2 + 1;

    if(leftChild > obj -> heapIndex) {
        return;
    }

    if(rightChild > obj -> heapIndex && leftChild == obj -> heapIndex) {
        if(myHeap[leftChild] < myHeap[currentIndex]) {
            swapNode(currentIndex, leftChild);
        }

        return;
    }

    if(myHeap[leftChild] < myHeap[currentIndex]) {
        swapNode(currentIndex, leftChild);

        bubbleDown(obj, leftChild);
    }

    if(myHeap[rightChild] < myHeap[currentIndex]) {
        swapNode(currentIndex, rightChild);

        bubbleDown(obj, rightChild);
    }
}

int deleteMinElement(KthLargest *obj) {
    swapNode(topIndex, obj -> heapIndex);
    obj -> heapIndex--;

    bubbleDown(obj, topIndex);

    return myHeap[obj -> heapIndex + 1];
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
