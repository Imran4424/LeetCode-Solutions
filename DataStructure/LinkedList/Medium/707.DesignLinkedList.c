
int initValue = -32005;

typedef struct MyLinkedList{
	int data;
	struct MyLinkedList *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
	MyLinkedList *temp = malloc(sizeof(MyLinkedList));
	temp - data = initValue;
	temp -> next = NULL;

	return temp;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* head, int index) {
  
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* head, int val) {
	// when linkedlist is empty
	if(initValue == head -> data) {
		head -> data = val;
		return;
	}

	MyLinkedList *temp = malloc(sizeof(MyLinkedList));
	temp -> data = val;
	temp -> next = head;

	head = temp;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* head, int val) {
	// when linkedlist is empty
	if(initValue == head -> data) {
		head -> data = val;
		return;
	}

	MyLinkedList *traval = head;

	while(traval -> next != NULL) {
		traval = traval -> next;
	}

	MyLinkedList *temp = malloc(sizeof(MyLinkedList));
	temp -> data = val;
	temp -> next = NULL;

	traval -> next = temp;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* head, int index, int val) {
  
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* head, int index) {
	if(initValue == head -> val) {
		return;
	}

	if(NULL == head -> next && 0 == index) {
		head -> val = initValue;
		return;
	}

	if(0 == index) {
		head = head -> next;
		return;
	}

	MyLinkedList *traval = head;

	while(index > 1 && )
}

void myLinkedListFree(MyLinkedList* head) {
	free(head);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* head = myLinkedListCreate();
 * int param_1 = myLinkedListGet(head, index);
 
 * myLinkedListAddAtHead(head, val);
 
 * myLinkedListAddAtTail(head, val);
 
 * myLinkedListAddAtIndex(head, index, val);
 
 * myLinkedListDeleteAtIndex(head, index);
 
 * myLinkedListFree(head);
*/