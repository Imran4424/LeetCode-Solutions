
const int topIndex = 1;
const int heapSize = 100000;

int heap[100001];
int heapIndex;

void swapNode(int source, int destination) {
	int temp = heap[source];
	heap[source] = heap[destination];
	heap[destination] = temp;
}

int parent(int currentIndex) {
	return currentIndex / 2;
}

void insert(int data) {
	if(heapIndex >= heapSize) {
		return;
	}

	heap[++heapIndex] = data;

	int currentIndex = heapIndex;
	int parentIndex = parent(currentIndex);

	while(currentIndex > 1 && heap[currentIndex] < heap[parentIndex]) {
		swapNode(currentIndex, parentIndex);
		currentIndex = parentIndex;
		parentIndex = parent(currentIndex);
	}
}

void bubbleDown(int currentIndex) {
	if (currentIndex > heapIndex) {
		return;
	}

	int leftChild = currentIndex * 2;
	int rightChild = currentIndex * 2 + 1;

	int smallest = currentIndex;

	if (leftChild <= heapIndex && heap[leftChild] < heap[smallest]) {
		smallest = leftChild;
	}

	if (rightChild <= heapIndex && heap[rightChild] < heap[smallest]) {
		smallest = rightChild;
	}

	if (smallest != currentIndex) {
		swapNode(currentIndex, smallest);
		bubbleDown(smallest);
	}
}

int deleteMinElement() {
	if(heapIndex < topIndex) {
		return -1;
	}

	swapNode(topIndex, heapIndex);
	heapIndex--;

	bubbleDown(topIndex);
	return heap[heapIndex + 1];
}


int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int targetIndex){
	heapIndex = 0;

	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < *matrixColSize; j++) {
			insert(matrix[i][j]);
		}
	}

	int targetElement;

	for (int i = 1; i <= targetIndex; i++) {
		targetElement = deleteMinElement();
	}

	return targetElement;
}