/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    
    if(NULL == head || NULL == head -> next ) {
        return head;
    }
    
    struct ListNode* newHead = reverseList(head -> next);
    
    head -> next = NULL;
    
    struct ListNode* travel = newHead;
    
    while(NULL != travel -> next) {
        travel = travel -> next;
    }
    
    travel -> next = head;
    
    return newHead;
}