
const int heapSize = 1000;
const int topIndex = 1;


int heap[1001];
int heapIndex;

void swapNode(int source, int destination) {
        int temp = heap[source];

        heap[source] = heap[destination];
        heap[destination] = temp;
}

void bubbleUp(int currentIndex) {
        int parentIndex = currentIndex / 2;

        if(parentIndex < topIndex) {
                return;
        }

        if(heap[currentIndex] > heap[parentIndex]) {
                swapNode(currentIndex, parentIndex);

                bubbleUp(parentIndex);
        }
}

void insertHeap(int data) {
        if(heapIndex >= heapSize) {
                return;
        }

        heapIndex++;
        heap[heapIndex] = data;

        bubbleUp(heapIndex);
}

void bubbleDown(int currentIndex) {
        if (currentIndex >= heapIndex) {
                return;
        }

        int leftChild = currentIndex * 2;
        int rightChild = currentIndex * 2 + 1;

        int biggest = currentIndex;

        if (leftChild <= heapIndex && heap[leftChild] > heap[biggest]) {
                biggest = leftChild;
        }

        if (rightChild <= heapIndex && heap[rightChild] > heap[biggest]) {
                biggest = rightChild;
        }

        if (currentIndex != biggest) {
                swapNode(currentIndex, biggest);
                bubbleDown(biggest);
        }
}

int deleteMaxElement() {
    swapNode(topIndex, heapIndex);
    heapIndex--;
    bubbleDown(topIndex);

    return heap[heapIndex + 1];
}


int lastStoneWeight(int* stones, int stonesSize){
        /// init heapIndex
        heapIndex = 0;

        /// creating heap
        for(int i = 0; i < stonesSize; i++) {
                insertHeap(stones[i]);
        }

        while(heapIndex >= 2) {
                int x = deleteMaxElement();
                int y = deleteMaxElement();

                if(x != y) {
                        insertHeap(x - y);
                }
        }

        if(0 == heapIndex) {
                return 0;
        }

        return heap[heapIndex];
}

