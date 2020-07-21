/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	ListNode *travelA = headA;
	ListNode travelB = headB;

	int countA = 0, countB = 0;



	while(NULL != travelA && NULL != travelB) {
		countA++;
		countB++;

		travelA = travelA -> next;
		travelB = travelB -> next;
	}

	
}