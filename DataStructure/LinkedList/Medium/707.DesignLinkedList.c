
const int initValue = -32005;

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


void printMyList(MyLinkedList *head) {
	MyLinkedList *travel = head;

	while(NULL != travel) {
		printf("%d ", travel -> data);
		travel = travel -> next;
	}

	printf("\n");
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* head, int index) {
	MyLinkedList *travel = head;

	printMyList(head);

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
	printMyList(head);

	// when linkedlist is empty
	if(initValue == head -> data) {
		head -> data = val;
		return;
	}

	MyLinkedList *temp = malloc(sizeof(MyLinkedList));
	temp -> data = val;
	temp -> next = head;

	head = temp;
	printf("After add\n");
	printMyList(head);

}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* head, int val) {
	printMyList(head);

	// when linkedlist is empty
	if(initValue == head -> data) {
		head -> data = val;
		return;
	}

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
	printMyList(head);

	if(0 != index && initValue == head -> data) {
		return;
	}

	if(0 == index) {
		myLinkedListAddAtHead(head, val);
		return;
	}

	if(1 == index && NULL == head -> next) {
		myLinkedListAddAtTail(head, val);
		return;
	}

	MyLinkedList *prev = head;
	MyLinkedList *travel = head -> next;
	index--; // cause we are traveling from the second node

	if(NULL == travel) {
		return;
	}

	while(NULL != travel -> next && index > 0) {
		index--;
		travel = travel -> next;
	}

	MyLinkedList *temp = malloc(sizeof(MyLinkedList));
	temp -> data = val;

	if(0 == index) {
		temp -> next = travel;
		prev -> next = temp;
	}

	if(NULL == travel -> next && 1 == index) {
		temp -> next = NULL;
		travel -> next = temp;
	}
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* head, int index) {
	printMyList(head);

	// list is empty
	if(initValue == head -> data) {
		return;
	}

	if(NULL == head -> next && 0 == index) {
		head -> data = initValue;
		return;
	}

	if(0 == index) {
		head = head -> next;
		return;
	}

	MyLinkedList *travel = head;

	while(index > 1 && NULL != travel -> next) {
		index--;
		travel = travel -> next;
	}

	if(NULL != travel -> next) {
		travel -> next = travel -> next -> next;
	}
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