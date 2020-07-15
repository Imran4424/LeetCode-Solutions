/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode *detectCycle(struct ListNode *head) {
	if(NULL == head || NULL == head -> next) {
		return NULL;
	}

	bool cycleFound = false;

	ListNode* travelSlow = head;
	ListNode* travelFast = head -> next;

	while(NULL != travelFast -> next && NULL != travelFast -> next -> next) {
		
		travelSlow = travelSlow -> next;
		travelFast = travelFast -> next -> next;

		if(travelFast == travelSlow) {
			cycleFound = true;
			break;
		}
	}

	printf("first while end\n");
	if(!cycleFound) {
		return NULL;
	}

	travelSlow = head;

	printf("Second while start\n");

	while(travelSlow != travelFast) {
		travelSlow = travelSlow -> next;
		travelFast = travelFast -> next;
	}

	printf("Second while end\n");

	return travelSlow;
}

