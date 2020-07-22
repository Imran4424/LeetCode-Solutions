/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

int listLength(ListNode* travel) {
	int length = 0;

	while(NULL != travel) {
		length++;

		travel = travel -> next;
	}
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	ListNode *travelA = headA;
	ListNode *travelB = headB;

	int countA = 0, countB = 0;



	while(NULL != travelA && NULL != travelB) {
		countA++;
		countB++;

		travelA = travelA -> next;
		travelB = travelB -> next;
	}

	while(NULL != travelA) {
		countA++;

		travelA = travelA -> next;
	}

	while(NULL != travelB) {
		countB++;

		travelB = travelB -> next;
	}

	if(travelA > travelB) {
		for(int i = 1; i <= travelA - travelB; i++) {
			headA = headA -> next;
		}
	} else {
		for(int i = 1; i <= travelB - travelA; i++) {
			headB = headB -> next;
		}
	}

	while(NULL != headA && NULL != headB && headA != headB) {
		headA = headA -> next;
		headB = headB -> next;
	}

	if(NULL == headA || NULL == headB) {
		return NULL;
	}

	return headA;
}