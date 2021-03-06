/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* listOne, struct ListNode* listTwo){
    if(NULL == listTwo) {
        return listOne;
    }
    
    if(NULL == listOne) { // list one null but list two not
        return listOne = listTwo;
    }
    
    if(listOne -> val > listTwo -> val) {
        struct ListNode* insertedNode = listTwo;
        listTwo = listTwo -> next;
        
        insertedNode -> next = listOne;
        listOne = insertedNode;
    }
    
    listOne -> next = mergeTwoLists(listOne -> next, listTwo);
    
    return listOne;
}