
const int initValue = -31520;

typedef struct MyLinkedList{
	int data;
    	struct MyLinkedList *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    	MyLinkedList *temp = malloc(sizeof(MyLinkedList));
	temp -> data = initValue;
	temp -> next = NULL;

	return temp;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* head, int index) {
	MyLinkedList *travel = head -> next;

	if (NULL == travel) {
		return -1;
	}

	while(NULL != travel -> next && index > 0) {
		index--;
		travel = travel -> next;
	}

	if(0 != index) {
		return -1;
	}

	return travel -> data;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* head, int val) {
	MyLinkedList *temp = malloc(sizeof(MyLinkedList));
	temp -> data = val;
	temp -> next = head -> next;

	head -> next = temp;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* head, int val) {
	MyLinkedList *travel = head;

	while(travel -> next != NULL) {
		travel = travel -> next;
	}

	MyLinkedList *temp = malloc(sizeof(MyLinkedList));
	temp -> data = val;
	temp -> next = NULL;

	travel -> next = temp;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* head, int index, int val) {

	MyLinkedList *prev = head;
	MyLinkedList *travel = head -> next;

	
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  
}

void myLinkedListFree(MyLinkedList* obj) {
	free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/