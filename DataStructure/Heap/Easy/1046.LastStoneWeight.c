
const int heapSize = 1000;
const int topIndex = 1;



int heapIndex;

void swapNode(int *heap, int source, int destination) {
    int temp = heap[source];

    heap[source] = heap[destination];
    heap[destination] = temp;
}

void bubbleUp(int *heap, int currentIndex) {
    int parentIndex = currentIndex / 2;

    if(parentIndex < topIndex) {
        return;
    }

    if(heap[currentIndex] > heap[parentIndex]) {
        swapNode(heap, currentIndex, parentIndex);

        bubbleUp(heap, parentIndex);
    }
}

void insertHeap(int *heap, int data) {
    if(heapIndex >= heapSize) {
        return;
    }

    heapIndex++;
    heap[heapIndex] = data;

    bubbleUp(heap, heapIndex);
}

void bubbleDown(int *heap, int currentIndex) {
    int leftChild = currentIndex * 2;
    int rightChild = currentIndex * 2 + 1;

    if(leftChild > heapIndex) {
        return;
    }

    if(rightChild > heapIndex && leftChild == heapIndex) {
        if(heap[leftChild] > heap[currentIndex]) {
            swapNode(heap, currentIndex, leftChild);
        }

        return;
    }

    if(heap[leftChild] > heap[currentIndex]) {
        swapNode(heap, currentIndex, leftChild);

        bubbleDown(heap, leftChild);
    }

    if(heap[rightChild] > heap[currentIndex]) {
        swapNode(heap, currentIndex, rightChild);

        bubbleDown(heap, rightChild);
    }
}

int deleteMaxElement(int *heap) {
    swapNode(heap, topIndex, heapIndex);
    heapIndex--;
    bubbleDown(heap, topIndex);

    return heap[heapIndex + 1];
}


int lastStoneWeight(int* stones, int stonesSize){
    /// init heapIndex
    int heap[heapSize + 1];
    heapIndex = 0;

    /// creating heap

    for(int i = 0; i < stonesSize; i++) {
        insertHeap(heap, stones[i]);
    }

    while(heapIndex >= 2) {
        int x = deleteMaxElement(heap);
        int y = deleteMaxElement(heap);

        if(x != y) {
            insertHeap(heap, x - y);
        }
    }

    if(0 == heapIndex) {
        return 0;
    }

    return heap[heapIndex];
}

