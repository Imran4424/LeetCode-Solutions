/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){

    while(NULL != head && head -> val == val) {
        head = head -> next;
    }
    
    if(NULL != head){
        head -> next = removeElements(head -> next, val);
    }
    
    return head;
}