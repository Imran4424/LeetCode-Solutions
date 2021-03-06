

int hashCode(int givenNum) {
	return givenNum % 100;
}

typedef struct HashNode
{
	int data;
	struct HashNode* next;	
} HashNode;

HashNode* getNode(int value) {
	HashNode* node = malloc(sizeof(HashNode));
	node -> data = value;
	node -> next = NULL;

	return node;
}

HashNode* hashHead[100];

void initHash() {
	for (int i = 0; i < 100; i++) {
		hashHead[i] = NULL;
	}
}

HashNode* hashInsert(HashNode* head, int value) {
	HashNode *temp = getNode(value);

	if (NULL == head) {
		head = temp;
	} else {
		temp -> next = head;
		head = temp;
	}

	return head;
}

bool hashSearch(HashNode* head, int target) {
	while (NULL != head) {
		if (target == head -> data) {
			return true;
		}

		head = head -> next;
	}

	return false;
}


int findDuplicate(int* nums, int numsSize) {
	initHash();

	for(int i = 0; i < numsSize; i++) {
		int x = nums[i];
		int code = hashCode(x);

		if(hashSearch(hashHead[code], x)) {
			return x;
		} else {
			hashHead[code] = hashInsert(hashHead[code], x);
		}
	}

	return nums[0];    
}