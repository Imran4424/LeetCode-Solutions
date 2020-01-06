/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    

    while(NULL != node -> next -> next) {
        node -> val = node -> next -> val;
        
        node = node -> next;
    }
    
    node -> val = node -> next -> val;
    node -> next = NULL;
}