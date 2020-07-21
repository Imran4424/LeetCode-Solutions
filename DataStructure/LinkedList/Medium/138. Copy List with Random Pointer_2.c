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

    // copying the linked list
    // setting random pointer of copy list to main list respective nodes

    Node *newListHead = malloc(sizeof(Node));
    newListHead -> val = head -> val;
    newListHead -> next = head -> next;
    newListHead -> random = head;
    
    Node* travel = head -> next;
    Node* copyTravel = newListHead;
    
    // set main list next pointer to respective copy list node
    Node* prev = head -> next;
    head -> next = newListHead;

    while(NULL != travel) {
    	Node* temp = malloc(sizeof(Node));
    	temp -> val = travel -> val;
    	temp -> next = travel -> next;
    	temp -> random = travel;

    	copyTravel -> next = temp;

    	travel = travel -> next;
        
        prev -> next = copyTravel -> next;
        prev = travel;

    	copyTravel = copyTravel -> next;
    }

    // set copy list random pointer to main list random -> next pointer

    copyTravel = newListHead;

    while(NULL != copyTravel) {
    	// using this rule
    	if(NULL == copyTravel -> random -> random) {
    		copyTravel -> random = NULL;
    	} else {
	    	copyTravel -> random = copyTravel -> random -> random -> next;
    	}

    	copyTravel = copyTravel -> next;
    }

    return newListHead;
}



