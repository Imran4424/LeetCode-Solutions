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

	return length;
}

int absolute(int x) {
	if(x < 0) {
		return -x;
	}

	return x;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	ListNode *travelA = headA;
	ListNode *travelB = headB;

	int lengthOne = listLength(headA);
	int lengthTwo = listLength(headB);
	int distance =  absolute(lengthOne - lengthTwo);

	
	if(travelA > travelB) {
		for(int i = 1; i < absolute; i++) {
			headA = headA -> next;
		}
	} else {
		for(int i = 1; i < absolute; i++) {
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