// TLE

typedef struct HashNode
{
	int data;
	struct HashNode *next;
} HashNode;

HashNode* hashTable[10000];
int hashSize = 10000;

void initHashTable() {
	for (int i = 0; i < hashSize; i++) {
		hashTable[i] = NULL;
	}
}

int getHashCode(int value) {
	if(value < 0) {
		value = -value;
	}

	return value % hashSize;
}

HashNode* newHashNode(int value) {
	HashNode* temp = malloc(sizeof(HashNode));

	temp -> data = value;
	temp -> next = NULL;

	return temp;
}

HashNode* insertNode(HashNode* head, int value) {
	HashNode* temp = newHashNode(value);

	temp -> next = head;
	head = temp;

	return head;
}

bool searchNode(HashNode* travel, int target) {
	while(NULL != travel) {
		if(target == travel -> data) {
			return true;
		}
	}

	return false;
}

bool containsDuplicate(int* nums, int numsSize) {
	initHashTable();

	for (int i = 0; i < numsSize; i++) {
		int hashCode = getHashCode(nums[i]);

		if(searchNode(hashTable[hashCode], nums[i])) {
			return true;
		} else {
			hashTable[hashCode] = insertNode(hashTable[hashCode], nums[i]);
		}
	}

	return false;
}