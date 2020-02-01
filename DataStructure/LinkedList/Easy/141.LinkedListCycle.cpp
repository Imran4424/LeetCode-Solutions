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
    bool hasCycle(ListNode *head) {
        if(NULL == head || NULL == head -> next) {
            return false;
        }
        
        if(-999 == head -> val) {
            return true;
        }
        
        head -> val = -999;
        
        return hasCycle(head -> next);
    }
};