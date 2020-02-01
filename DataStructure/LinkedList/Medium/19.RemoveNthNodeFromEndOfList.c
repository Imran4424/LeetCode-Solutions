/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int buffer = 1000;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(NULL == head) {
        struct ListNode *temp = malloc(sizeof(struct ListNode));
        temp -> val = buffer + n - 1;
        temp -> next = NULL;
        
        return temp;
    }
    
    struct ListNode *outNode = removeNthFromEnd(head -> next, n);
    
    if(NULL == outNode) {
        head -> next = outNode;
        return head;
    }
    
    if(buffer == outNode -> val && NULL == outNode -> next) {
        return head -> next;
    } else if(outNode -> val > buffer && NULL == outNode -> next) {
        outNode -> val = outNode -> val - 1;
        return outNode;
    } else {
        head -> next = outNode;
        return head;
    }
}

