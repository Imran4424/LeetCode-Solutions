/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int currentN = -7;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if(NULL == head -> next && 1 == n) {
		return NULL;
	}

	if(NULL == head -> next) {
		currentN = n - 1;
		return head;
	}

	head -> next = removeNthFromEnd(head -> next, n);

	if(1 == currentN) {
		currentN = -100;
		return head -> next;
	} else if (currentN > 1) {
		currentN--;
	}

	return head;
}