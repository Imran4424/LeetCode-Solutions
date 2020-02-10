/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void merge(struct ListNode **arr,struct ListNode  **left, int leftSize, struct ListNode **right, int rightSize) {
    int i = 0, j = 0, index = 0;

    while(i < leftSize && j < rightSize) {
        if(left[i] -> val < right[j] -> val) {
            arr[index] = left[i++];
        } else {
            arr[index] = right[j++];
        }

        index++;
    }

    while(i < leftSize) {
        arr[index++] = left[i++];
    }

    while(j < rightSize) {
        arr[index++] = right[j++];
    }
}

void mergeSort(struct ListNode **arr, int aSize) {
    if(aSize < 2) {
        return;
    }

    int mid = aSize / 2;
    struct ListNode* left[mid];
    struct ListNode* right[aSize - mid];

    int index = 0;

    for(int i = 0; i < mid; i++) {
        left[i] = arr[index++];
    }

    for(int i = 0; i < aSize - mid; i++) {
        right[i] = arr[index++];
    }

    mergeSort(left, mid);
    mergeSort(right, aSize - mid);

    merge(arr, left, mid, right, aSize - mid);
}


struct ListNode* sortList(struct ListNode* head){
    if(NULL == head || NULL == head -> next) {
        return head;
    }

    struct ListNode* listArr[90001];
    int index = 0;

    while(NULL != head) {
        struct ListNode* insertedNode = head;
        head = head -> next;
        insertedNode -> next = NULL;

        listArr[index++] = insertedNode;
    }

    mergeSort(listArr, index);

    struct ListNode* newHead = listArr[0];
    struct ListNode* travel = newHead;

    for(int i = 1; i < index; i++) {
        while(NULL != travel -> next) {
            travel = travel -> next;
        }

        travel -> next = listArr[i];
    }

    return newHead;
}

