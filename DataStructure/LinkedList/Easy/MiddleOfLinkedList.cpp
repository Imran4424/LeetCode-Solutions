/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *travel = head;
    
    int nodeCount = 0;
    
    while(NULL != travel) {
        nodeCount++;
        travel = travel -> next;
    }

    nodeCount = nodeCount / 2;
    
    travel = head;
    
    while(nodeCount--) {
        travel = travel -> next;
    }
    
    return travel;
}
