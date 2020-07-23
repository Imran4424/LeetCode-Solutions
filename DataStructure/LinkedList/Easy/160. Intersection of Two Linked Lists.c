/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

int absolute(int x) {
	if(x < 0) {
		return -x;
	}

	return x;
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

	int distance = absolute(countA - countB);

	if(countA > countB) {
		for(int i = 1; i <= distance; i++) {
			headA = headA -> next;
		}
	} else {
		for(int i = 1; i <= distance; i++) {
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