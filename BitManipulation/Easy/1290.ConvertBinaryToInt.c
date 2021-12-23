/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getDecimalValue(struct ListNode* head) {
    int decimal = 0;
    
    while(NULL != head) {
        
        decimal = decimal * 2 + head -> val;
        
        head = head -> next;
    }
    
    return decimal;
}