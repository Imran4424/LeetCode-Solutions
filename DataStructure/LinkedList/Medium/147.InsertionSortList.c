/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* sortedInsert(struct ListNode* head, struct ListNode* insertedNode) {
    if(NULL == head) {
        head = insertedNode;

        return head;
    }

    if(head -> val > insertedNode -> val) {
        insertedNode -> next = head;
        head = insertedNode;

        return head;
    }

    struct ListNode* travel = head;

    while(NULL != travel -> next) {
        if(travel -> next -> val > insertedNode -> val) {
            insertedNode -> next = travel -> next;
            travel -> next = insertedNode;

            return head;
        }

        travel = travel -> next;
    }

    travel -> next = insertedNode;

    return head;
}

struct ListNode* insertionSortList(struct ListNode* head){
    if(NULL == head || NULL == head -> next) {
        return head;
    }

    struct ListNode* newhead = NULL;

    while(NULL != head) {
        struct ListNode* insertedNode = head;
        head = head -> next;
        insertedNode -> next = NULL;

        newhead = sortedInsert(newhead, insertedNode);
    }

    return newhead;
}

