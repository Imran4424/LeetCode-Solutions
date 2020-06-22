/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode* swapPairs(struct ListNode* head) {
	if(NULL == head || NULL == head -> next) {
		return head;
	}

	ListNode* travelOne = head;
	ListNode* travelTwo = head -> next;
}