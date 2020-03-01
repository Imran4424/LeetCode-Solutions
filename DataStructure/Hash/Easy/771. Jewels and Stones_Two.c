
typedef struct HashTable
{
	char ch;
	struct HashTable *next;
};

const int hashSize = 26;

int hashKey(char letter) {
	
	int key;

	if(letter >= 'A' && letter <= 'Z') {
		key = letter - 'A';
	} else {
		key = letter - 'a';
	}

	return key;
}

HashTable* hashCreate(char letter) {
	HashTable* temp = malloc(sizeof(HashTable));

	temp -> ch = letter;
	temp -> next = NULL;

	return temp;
}

void initHash(HashTable **head) {
	for(int i = 0; i < hashSize; i++) {
		head[i] = NULL;
	}
}

HashTable* insertHash(HashTable *head, char letter) {
	HashTable* temp = hashCreate(letter);
	temp -> NULL = head;

	head = temp;

	return head;
}

bool searchHash(HashTable *travel, char letter) {
	while(NULL != travel) {
		if(letter == travel -> ch) {
			return true;
		}
	}

	return false;
}

int numJewelsInStones(char * jewels, char * stones) {
	HashTable *head[26];
	initHash(head);

	for(int i = 0; jewels[i]; i++) {
		int key = hashKey(jewels[i]);

		head[key] = insertHash(head[key], jewels[i]);
	}

	int jewelCount = 0;

	for(int i = 0; stones[i]; i++) {
		int key = hashKey(stones[i]);

		if(searchHash(head[key], stones[i])) {
			jewelCount++;
		}
	}

	return jewelCount;
}