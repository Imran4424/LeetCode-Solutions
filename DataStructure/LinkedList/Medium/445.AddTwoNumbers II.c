/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    
	if(NULL == head || NULL == head -> next) {
		return head;
	}

	struct ListNode *newHead = NULL, *travel = head;

	while(NULL != travel) {
		struct ListNode* InsertNode = malloc(sizeof(struct ListNode));
		InsertNode -> val = travel -> val;
		InsertNode -> next = newHead;
		newHead = InsertNode;

		travel = travel -> next;
	}

	return newHead;
}

struct ListNode* addTwoNumbers(struct ListNode* listOne, struct ListNode* listTwo){
	listOne = reverseList(listOne);
	listTwo = reverseList(listTwo);

	int carry = 0;
	struct ListNode * newList = NULL;
	struct ListNode *travel;
    
	while(NULL != listOne && NULL != listTwo) {
		int digitOne = listOne -> val;
		int digitTwo = listTwo -> val;

		int result = digitOne + digitTwo + carry;

		carry = result / 10;

		struct ListNode *temp = malloc(sizeof(struct ListNode));
		temp -> val = result % 10;
		temp -> next = NULL;
        
		if(NULL == newList) {
			newList = temp;
			travel = newList;
		} else {
			while(NULL != travel -> next) {
				travel = travel -> next;
			}

			travel -> next = temp;
		}
        
        
	        listOne = listOne -> next;
	        listTwo = listTwo -> next;
    	}
    
	while(NULL != listOne) {
		int digitOne = listOne -> val;
		int result = digitOne + carry;

		carry = result / 10;

		struct ListNode *temp = malloc(sizeof(struct ListNode));
		temp -> val = result % 10;
		temp -> next = NULL;

		while(NULL != travel -> next) {
			travel = travel -> next;
		}
	    
		travel -> next = temp;

		listOne = listOne -> next;
	}
    
	while(NULL != listTwo) {
		int digitTwo = listTwo -> val;
		int result = digitTwo + carry;

		carry = result / 10;

		struct ListNode *temp = malloc(sizeof(struct ListNode));
		temp -> val = result % 10;
		temp -> next = NULL;

		while(NULL != travel -> next) {
			travel = travel -> next;
		}
	    
		travel -> next = temp;

		listTwo = listTwo -> next;
	}
    
	if(carry > 0) {
		struct ListNode *temp = malloc(sizeof(struct ListNode));
		temp -> val = carry;
		temp -> next = NULL;

		//printf("Hi");
		while(NULL != travel -> next) {
			//printf("inside while");
			travel = travel -> next;
		}
	    
		travel -> next = temp;
	}

	newList = reverseList(newList);
    
	return newList;
}

