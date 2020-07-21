/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */

 /*
	this link has the solution concept
	https://www.youtube.com/watch?v=EHpS2TBfWQg
 */

typedef struct Node Node;

struct Node* copyRandomList(struct Node* head) {
    if(NULL == head) {
    	return head;
    }

    Node *newListHead = malloc(sizeof(Node));
    newListHead -> val = head -> val;
    newListHead -> next = head -> next;
    newListHead -> random = head;

    Node* prev = head;
    Node* travel = head -> next;
    Node* newTravel = newListHead;
    prev -> next = head;

    while(NULL != travel) {
    	Node* temp = malloc(sizeof(Node));
    	temp -> val = travel -> val;
    	temp -> next = travel -> next;
    	temp -> random = travel;

    	newTravel -> next = temp;

    	travel = travel -> next;
    	newTravel = newTravel -> next;
    }


    return newListHead;
}