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
    ListNode* mergeTwoLists(ListNode* listOne, ListNode* listTwo) {
        
        if(NULL == listTwo) {
            return listOne;
        }
        
        if(NULL == listOne) {
            return listOne = listTwo;
        }
        
        if(listOne -> val > listTwo -> val) { 
            
            ListNode* insertedNode = listTwo;
            
            listTwo = listTwo -> next;
            
            insertedNode -> next = listOne;
            
            listOne = insertedNode;
        }
        
        listOne -> next = mergeTwoLists(listOne -> next, listTwo);
        
        return listOne;
    }
};