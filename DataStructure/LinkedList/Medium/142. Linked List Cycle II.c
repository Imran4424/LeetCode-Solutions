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

	int foundCyclePosition = -1;

	ListNode* travel = head;

}

