
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
	solution concept
	
	let's say, 
	linked list 1 length is 7
	linked list 2 length is 5

	total length 12

	after 2x total iteration
	they will meet at insection point
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

		// If one of them reaches the end earlier then reuse it 
	        // by moving it to the beginning of other list.
	        // Once both of them go through reassigning, 
	        // they will be equidistant from the collision point.

		if (NULL == travelA) {
			travelA = headB;
		}

		if (NULL == travelB) {
			travelB = headA;
		}
	}

	return travelA;
}