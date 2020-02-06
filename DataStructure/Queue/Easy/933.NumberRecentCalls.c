

typedef struct {
    int currentSize;
} RecentCounter;

int Stack[10005];
int front, rear;

RecentCounter* recentCounterCreate() {
    RecentCounter *temp = malloc(sizeof(RecentCounter));
    temp -> currentSize = 0;

    front = rear = 0;

    return temp;
}

int recentCounterPing(RecentCounter* obj, int t) {
    int validTime = t - 3000;

    if(t > validTime) {
        Stack[rear++] = t;
        obj->currentSize++;
    }

    while(Stack[front] < validTime) {
        front++;
        obj->currentSize--;
    }

    return obj->currentSize;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/
