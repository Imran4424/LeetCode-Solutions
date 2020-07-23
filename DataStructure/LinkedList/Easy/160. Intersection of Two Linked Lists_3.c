
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

	while(NULL != travelA && NULL != travelB && travelA != travelB) {
		travelA = travelA -> next;
		travelB = travelB -> next;

		// Any time they collide or reach end together without colliding 
	        // then return any one of the pointers.

		if(travelA == travelB) {
			return travelA;
		}


		if (NULL == travelA) {
			travelA = headB;
		}

		if (NULL == travelB) {
			travelB = headA;
		}
	}

	return travelA;
}