
const int topIndex = 1;

int heapSize = 10000;
int heap[10001];
int heapIndex;

void swapNode(int source, int destination) {
	int temp = heap[source];
	heap[source] = heap[destination];
	heap[destination] = temp;
}

void bubbleUp(int currentIndex) {
	int parentIndex = currentIndex / 2;

	if (parentIndex < topIndex) {
		return;
	}

	if (heap[currentIndex]  < heap[parentIndex]) {
		swapNode(currentIndex, parentIndex);
		bubbleUp(parentIndex);
	}
}

void insertHeap(int data) {
	if (heapIndex >= heapSize) {
		if (data > heap[topIndex]) {
			deleteMinElement();
		} else {
			return;
		}
	}

	heapIndex++;
	heap[heapIndex] = data;
	bubbleUp(heapIndex);
}

void bubbleDown(int currentIndex) {
	int leftChild = currentIndex * 2;
	int rightChild = currentIndex * 2 + 1;

	if (leftChild > heapIndex) {
		return;
	}

	if (rightChild > heapIndex && leftChild == heapIndex) {
		if (heap[currentIndex] > heap[leftChild]) {
			swapNode(currentIndex, leftChild);
		}

		return;
	}

	if (heap[currentIndex] > heap[leftChild]) {
		swapNode(currentIndex, leftChild);
		bubbleDown(leftChild);
	}

	if (heap[currentIndex] > heap[rightChild]) {
		swapNode(currentIndex, rightChild);
		bubbleDown(rightChild);
	}
}

void deleteMinElement() {
	swapNode(topIndex, heapIndex);
	heapIndex--;
	bubbleDown(topIndex);
}

int findKthLargest(int* nums, int numsSize, int k) {
	heapIndex = 0;
	heapSize = k;

	for (int i = 0; i < numsSize; i++) {
		insertHeap(nums[i]);
	}

	return heap[topIndex];
}