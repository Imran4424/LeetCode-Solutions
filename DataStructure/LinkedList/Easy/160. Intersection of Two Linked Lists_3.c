
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if(NULL == headA || NULL == headB) {
		return NULL;
	}

	ListNode* travelA = headA;
	ListNode* travelB = headB;  

	
}