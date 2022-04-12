/*
	You are given an array of integers stones where stones[i] is the weight of 
	the ith stone.

	We are playing a game with the stones. On each turn, we choose the heaviest 
	two stones and smash them together. Suppose the heaviest two stones have 
	weights x and y with x <= y. The result of this smash is:

	    If x == y, both stones are destroyed, and
	    If x != y, the stone of weight x is destroyed, and the stone of weight y 
	    has new weight y - x.

	At the end of the game, there is at most one stone left.

	Return the smallest possible weight of the left stone. If there are no stones 
	left, return 0.

	
	Example 1:

	Input: stones = [2,7,4,1,8,1]
	Output: 1
	Explanation: 
	We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
	we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
	we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
	we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

	Example 2:

		Input: stones = [1]
		Output: 1

	Constraints:

		1 <= stones.length <= 30
		1 <= stones[i] <= 1000
*/

class Solution {
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

public:
	int lastStoneWeight(vector<int>& stones) {
		/// init heapIndex
	        heapIndex = 0;

	        /// creating heap
	        for(int i = 0; i < stones.size(); i++) {
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
};