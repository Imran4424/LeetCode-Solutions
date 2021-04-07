

typedef struct DistanceList {
        int pointX, pointY;
        int distance;
} DistanceList;

const int topIndex = 1;

DistanceList myHeap[10001];
int heapSize;
int heapIndex;

void swapNode(int source, int destination) {
        DistanceList temp = myHeap[source];
        myHeap[source] = myHeap[destination];
        myHeap[destination] = temp;
}

void bubbleDown(int currentIndex) {
        if (currentIndex >= heapIndex) {
                return;
        }

        int leftChild = currentIndex * 2;
        int rightChild = currentIndex * 2 + 1;

        int biggest = currentIndex;

        if (leftChild <= heapIndex && myHeap[leftChild].distance > myHeap[biggest].distance) {
                biggest = leftChild;
        }

        if (rightChild <= heapIndex && myHeap[rightChild].distance > myHeap[biggest].distance) {
                biggest = rightChild;
        }

        if (biggest != currentIndex) {
                swapNode(currentIndex, biggest);
                bubbleDown(biggest);
        }
}

DistanceList deleteMaxElement() {
        if (heapIndex < topIndex) {
                DistanceList temp;
                return temp;
        }

        swapNode(heapIndex, topIndex);
        heapIndex--;
        bubbleDown(topIndex);

        return myHeap[heapIndex + 1];
}

int getParent(int currentIndex) {
        return currentIndex / 2;
}

void heapInsert(DistanceList value) {
        if(heapIndex >= heapSize) {
                if(myHeap[topIndex].distance <= value.distance) {
                        return;
                }

                deleteMaxElement();
        }

        myHeap[++heapIndex] = value;

        int currentIndex = heapIndex;
        int parentIndex = getParent(heapIndex);

        while(currentIndex > 1 && myHeap[currentIndex].distance > myHeap[parentIndex].distance) {
                swapNode(currentIndex, parentIndex);

                currentIndex = parentIndex;
                parentIndex = getParent(currentIndex);
        }
}

void heapNode(int x, int y) {
        DistanceList temp;

        temp.pointX = x;
        temp.pointY = y;
        temp.distance = x * x + y * y;

        heapInsert(temp);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes){
	heapIndex = 0;
        heapSize = k;

	for(int i = 0 ; i < pointsSize; i++) {
                heapNode(points[i][0], points[i][1]);
	}

	for(int i = k - 1; i >= 0; i--) {
                DistanceList returnedNode = deleteMaxElement();

		points[i][0] = returnedNode.pointX;
                points[i][1] = returnedNode.pointY;
	}

	*returnSize = k;
	*returnColumnSizes = pointsColSize;

	return points;
}

