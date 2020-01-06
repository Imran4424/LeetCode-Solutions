/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){

    while(NULL != head && NULL != head -> next && head -> val == head -> next -> val) {
        head = head -> next;
    }
    
    if(NULL != head) {
        head -> next = deleteDuplicates(head -> next);
    }
    
    return head;
}
