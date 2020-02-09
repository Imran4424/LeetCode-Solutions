/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    
    if(NULL == head || NULL == head -> next) {
        return head;
    }
    
	struct ListNode *newHead = NULL, *travel = head;
    
    while(NULL != travel) {
        ListNode* InsertNode = new ListNode(travel -> val);
        
        InsertNode -> next = newHead;
        newHead = InsertNode;
        
        travel = travel -> next;
    }
    
    return newHead;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

}

