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
	ListNode* travelFast = head;

	while(NULL != travelSlow && NULL != travelFast && NULL != travelFast -> next) {
		
		travelSlow = travelSlow -> next;
		travelFast = travelFast -> next -> next;

		if(travelFast == travelSlow) {
			cycleFound = true;
			break;
		}
	}

	
	if(!cycleFound) {
		return NULL;
	}

	travelSlow = head;

	while(travelSlow != travelFast) {
		travelSlow = travelSlow -> next;
		travelFast = travelFast -> next;
	}

	return travelSlow;
}

