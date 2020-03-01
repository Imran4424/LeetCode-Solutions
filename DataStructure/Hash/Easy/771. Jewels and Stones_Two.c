
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

bool searchHash()

int numJewelsInStones(char * jewels, char * stones) {
	HashTable *head[26];
	initHash(head);


}