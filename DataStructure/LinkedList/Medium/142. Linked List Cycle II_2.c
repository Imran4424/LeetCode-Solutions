/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /*
	Math behind the solution

	Suppose, 
	first meet of two pointer after k steps
	length of the cycle, r
	so, 2k - k = nr
	or, k = nr

	now suppose,
	distance between start node of list and start node of cycle is, s
	distance between start node of list and first meeting node is, k
	distance between start node of cycle and first meeting node is, m

	so, s = k - m
	or, s = nr - m
	or, s = nr - r + r - m
	or, s = (n - 1) r + r - m

	now let's consider 1 loop, that means, n = 1
	so, s = (1 - 1) r + r - m
	or, s = 0.r + r - m
	or, s = r - m

	so, 
	distance between, (from) start node of the list and (to) start node of cycle is equal to
	distance between, (from) first meeting node and (to) start node of cycle

 */

typedef struct ListNode ListNode;

struct ListNode *detectCycle(struct ListNode *head) {
	if(NULL == head || NULL == head -> next) {
		return NULL;
	}

	bool cycleFound = false;

	ListNode* travelSlow = head;
	ListNode* travelFast = head;

	while(NULL != travelSlow -> next && NULL != travelFast -> next && NULL != travelFast -> next -> next) {
		
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










