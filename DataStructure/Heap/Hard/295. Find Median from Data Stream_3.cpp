class MaxHeap {
        int topIndex = 1;
        int heapIndex = 0;
        int heapSize;
        int *heap;

        void swapNode(int source, int destination) {
                int temp = heap[source];
                heap[source] = heap[destination];
                heap[destination] = temp;
        }

        int parent(int currentIndex) {
                return currentIndex / 2;
        }

        void bubbleDown(int currentIndex) {
                if (currentIndex > heapIndex) {
                        return;
                }

                int leftChild = currentIndex * 2;
                int rightChild = currentIndex * 2 + 1;

                int largest = currentIndex;

                if (leftChild <= heapIndex && heap[leftChild] > heap[largest]) {
                        largest = leftChild;
                }

                if (rightChild <= heapIndex && heap[rightChild] < heap[largest]) {
                        largest = rightChild;
                }

                if (largest != currentIndex) {
                        swapNode(currentIndex, largest);
                        bubbleDown(largest);
                }
        }

public:
        MaxHeap() { }

        MaxHeap(int heapSize) {
                this -> heapSize = heapSize;
                heap = new int[heapSize + 1];
        }

        void insert(int data) {
                if (heapIndex >= heapSize) {
                        return;
                }

                heap[++heapIndex] = data;
                
                // Fix the min heap property if it is violated
                int currentIndex = heapIndex;

                while(currentIndex != 0 && heap[currentIndex] > heap[parent(currentIndex)]) {
                        swapNode(currentIndex, parent(currentIndex));

                        currentIndex = parent(currentIndex);
                }

        }

        int deleteMaxElement() {
                if (heapIndex < topIndex) {
                        return 0;
                }

                swapNode(topIndex, heapIndex);
                heapIndex--;
                bubbleDown(topIndex);

                return heap[heapIndex + 1];
        }

        int top() {
                return heap[topIndex];
        }

        int size() {
                return heapIndex;
        }
};

class MinHeap {
        int topIndex = 1;
        int heapIndex = 0;
        int heapSize;
        int *heap;

        void swapNode(int source, int destination) {
                int temp = heap[source];
                heap[source] = heap[destination];
                heap[destination] = temp;
        }

        int parent(int currentIndex) {
                return currentIndex / 2;
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

public:
        MinHeap() { }

        MinHeap(int heapSize) {
                this -> heapSize = heapSize;
                heap = new int[heapSize + 1];
        }

        void insert(int data) {
                if (heapIndex >= heapSize) {
                        return;
                }

                heap[++heapIndex] = data;
                
                // Fix the min heap property if it is violated
                int currentIndex = heapIndex;

                while(currentIndex != 0 && heap[currentIndex] < heap[parent(currentIndex)]) {
                        swapNode(currentIndex, parent(currentIndex));

                        currentIndex = parent(currentIndex);
                }

        }

        int deleteMinElement() {
                if (heapIndex < topIndex) {
                        return 0;
                }

                swapNode(topIndex, heapIndex);
                heapIndex--;
                bubbleDown(topIndex);

                return heap[heapIndex + 1];
        }

        int top() {
                return heap[topIndex];
        }

        int size() {
                return heapIndex;
        }
};

class MedianFinder {
        MaxHeap maxHeap;
        MinHeap minHeap;

public:
        /** initialize your data structure here. */
        MedianFinder(): maxHeap(50000), minHeap(50000){ }

        void addNum(int num) {
                maxHeap.insert(num);
                minHeap.insert(maxHeap.deleteMaxElement());
                
                if (maxHeap.size() < minHeap.size()) {
                        maxHeap.insert(minHeap.deleteMinElement());
                }
        }

        double findMedian() {
                if (maxHeap.size() > minHeap.size()) {
                        return maxHeap.top();
                } else {
                        return ((double) maxHeap.top() + (double) minHeap.top()) / 2;
                }
        }
};

/**

Heaps are a natural ingredient for this dish! Adding elements to them take logarithmic order of time. They also give 
direct access to the maximal/minimal elements in a group.

If we could maintain two heaps in the following way:

A max-heap to store the smaller half of the input numbers
A min-heap to store the larger half of the input numbers

This gives access to median values in the input: they comprise the top of the heaps!

Wait, what? How?

If the following conditions are met:

Both the heaps are balanced (or nearly balanced)
The max-heap contains all the smaller numbers while the min-heap contains all the larger numbers

then we can say that:

All the numbers in the max-heap are smaller or equal to the top element of the max-heap (let's call it x)

All the numbers in the min-heap are larger or equal to the top element of the min-heap (let's call it y)

Then x and/or y are smaller than (or equal to) almost half of the elements and larger than (or equal to) the other half. 
That is the definition of median elements.

This leads us to a huge point of pain in this approach: balancing the two heaps!
------------------------------------------------------------------------------------------------------------------------
Algorithm

Two priority queues:

        1. A max-heap lo to store the smaller half of the numbers
        2. A min-heap hi to store the larger half of the numbers

The max-heap lo is allowed to store, at worst, one more element more than the min-heap hi. Hence if we have processed k elements:

        If k = 2*n + 1  then lo is allowed to hold n+1 elements, while hi can hold n elements. 
        If k = 2*n then both heaps are balanced and hold n elements each.

This gives us the nice property that when the heaps are perfectly balanced, the median can be derived from the tops of both 
heaps. Otherwise, the top of the max-heap lo holds the legitimate median.

Adding a number num:

Add num to max-heap lo. Since lo received a new element, we must do a balancing step for hi. So remove the largest element 
from lo and offer it to hi. 

The min-heap hi might end holding more elements than the max-heap lo, after the previous operation. We fix that by removing 
the smallest element from hi and offering it to lo.

The above step ensures that we do not disturb the nice little size property we just mentioned.

A little example will clear this up! Say we take input from the stream [41, 35, 62, 5, 97, 108]. The run-though of the 
algorithm looks like this:

Adding number 41
MaxHeap lo: [41]           // MaxHeap stores the largest value at the top (index 0)
MinHeap hi: []             // MinHeap stores the smallest value at the top (index 0)
Median is 41
=======================
Adding number 35
MaxHeap lo: [35]
MinHeap hi: [41]
Median is 38
=======================
Adding number 62
MaxHeap lo: [41, 35]
MinHeap hi: [62]
Median is 41
=======================
Adding number 4
MaxHeap lo: [35, 4]
MinHeap hi: [41, 62]
Median is 38
=======================
Adding number 97
MaxHeap lo: [41, 35, 4]
MinHeap hi: [62, 97]
Median is 41
=======================
Adding number 108
MaxHeap lo: [41, 35, 4]
MinHeap hi: [62, 97, 108]
Median is 51.5

*/