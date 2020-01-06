/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head){
    
        if(NULL == head || NULL == head -> next) {
            return head;
        }
        
        ListNode *newHead = NULL, *travel = head;
        
        while(NULL != travel) {
            ListNode* InsertNode = new ListNode(travel -> val);
            
            InsertNode -> next = newHead;
            newHead = InsertNode;
            
            travel = travel -> next;
        }
        
        return newHead;
    }
    
    bool isPalindrome(ListNode* head){
        ListNode* reverseHead = reverseList(head);

        while(NULL != head) {           
            if(head -> val != reverseHead -> val) {
                return false;
            }
            
            head = head -> next;
            reverseHead = reverseHead -> next;
        }

        return true;
    }
};