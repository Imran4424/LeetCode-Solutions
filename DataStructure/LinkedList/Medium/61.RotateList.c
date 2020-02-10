/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* singleRotateRight(struct ListNode* head) {
    struct ListNode* travel = head;

    while(NULL != travel -> next -> next) {
        travel = travel -> next;
    }

    struct ListNode* rotateNode = travel -> next;
    travel -> next = NULL;

    rotateNode -> next = head;
    head = rotateNode;

    return head;
}

int listLength(struct ListNode* head) {
    struct ListNode* travel = head;
    int length = 0;

    while(NULL != travel) {
        length++;
        travel = travel -> next;
    }

    return length;
}

struct ListNode* rotateRight(struct ListNode* head, int numRotations){
    if(NULL == head || NULL == head -> next) {
        return head;
    }

    int length = listLength(head);

    numRotations = numRotations % length;

    for(int i = 1; i <= numRotations; i++) {
        head = singleRotateRight(head);
    }

    return head;
}