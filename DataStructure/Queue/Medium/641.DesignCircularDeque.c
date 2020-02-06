

typedef struct {
    int data;
} MyCircularDeque;

int front, rear, qSize, currentSize;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
 	MyCircularDeque* temp = malloc(((2 * k) + 1) * sizeof(MyCircularDeque));
 	// front and rear need to be different in this case
 	front = k - 1;
 	rear = k;
    qSize = k;
    currentSize = 0;
 	return temp;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(front < 0 || currentSize == qSize) {
        return false;
    }

    obj[front--].data = value;
    currentSize++;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(currentSize == qSize) {
        return false;
    }
    obj[rear++].data = value;
    currentSize++;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(0 == currentSize) {
        return false;
    }

    front++;
    currentSize--;

    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(0 == currentSize) {
        return false;
    }

    rear--;
    currentSize--;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(0 == currentSize) {
        return -1;
    }

    return obj[front + 1].data;
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(0 == currentSize) {
        return -1;
    }
    return obj[rear - 1].data;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(0 == currentSize) {
        return true;
    }

    return false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(currentSize == qSize) {
        return true;
    }

    return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);

 * bool param_2 = myCircularDequeInsertLast(obj, value);

 * bool param_3 = myCircularDequeDeleteFront(obj);

 * bool param_4 = myCircularDequeDeleteLast(obj);

 * int param_5 = myCircularDequeGetFront(obj);

 * int param_6 = myCircularDequeGetRear(obj);

 * bool param_7 = myCircularDequeIsEmpty(obj);

 * bool param_8 = myCircularDequeIsFull(obj);

 * myCircularDequeFree(obj);
*/
