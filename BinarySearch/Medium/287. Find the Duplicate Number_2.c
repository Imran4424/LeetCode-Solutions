

int hashCode(int givenNum) {
	return givenNum % 100;
}

typedef struct HashNode
{
	int data;
	struct HashNode* next;	
} HashNode;

HashNode* getNode(int value) {
	HashNode* node;
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

void hashInsert(HashNode* head, int value) {
	HashNode *temp = getNode(value);

	if (NULL == head) {
		head = temp
		return;
	}

	temp -> next = head;
	head = temp;
}

bool hashSearch(HashNode* head, int value) {
	if (NULL == head) {
		return false;
	}

	
}


int findDuplicate(int* nums, int numsSize) {
	initHash();

	for(int i = 0; i < numsSize; i++) {
		if(vistied[nums[i]]) {
			return nums[i];
		} else {
			vistied[nums[i]] = 1;
		}
	}

	return nums[0];    
}