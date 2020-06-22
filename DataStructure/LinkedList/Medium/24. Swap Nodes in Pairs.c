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

	int nodeCount = 2;
	ListNode* prevNode = head;
	ListNode* currentNode = head -> next;

	while(NULL != currentNode) {
		// swapping
		if(nodeCount % 2 == 0) {
			int temp = prevNode -> val;
			prevNode -> val = currentNode -> val;
			currentNode -> val = temp;
		}

		prevNode = currentNode;
		currentNode = currentNode -> next;
		nodeCount++;
	}

	return head;
}