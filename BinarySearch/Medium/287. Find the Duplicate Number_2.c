

int hashCode(int givenNum) {
	return givenNum % 100;
}

typedef struct HashNode
{
	int data;
	struct HashNode* next;	
} HashNode;

HashNode* hashHead[100];

void initHash() {
	for(int i = 0; i < 100; i++) {
		hashHead[i] = NULL;
	}
}

void hashInsert(HashNode* head, int value) {
	
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