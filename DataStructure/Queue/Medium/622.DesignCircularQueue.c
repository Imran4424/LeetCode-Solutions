


typedef struct {
    int data;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

int front, rear, qSize, currentSize;

MyCircularQueue* myCircularQueueCreate(int size) {
    MyCircularQueue *newQueue = malloc(size * sizeof(MyCircularQueue));
    front = rear = 0;
    qSize = size;
    currentSize = 0;

    return newQueue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(currentSize == qSize) {
        return false;
    }

    if(rear == qSize) {
        rear = 0;
    }

    obj[rear++].data = value;
    currentSize++;

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(currentSize == 0) {
        return false;
    }

    if(front == qSize){
        front = 0;
    }

    front++;
    currentSize--;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(0 == currentSize) {
        return -1;
    }

    if(front == qSize) {
        front = 0;
    }

    return obj[front].data;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if(0 == currentSize) {
        return -1;
    }

    return obj[rear - 1].data;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(0 == currentSize) {
        return true;
    }

    return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(qSize == currentSize) {
        return true;
    }

    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
