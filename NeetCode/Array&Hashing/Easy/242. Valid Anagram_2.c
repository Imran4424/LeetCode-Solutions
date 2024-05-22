
typedef struct HashTable
{
	int fCount;
	struct HashTable *next;
} HashTable;

const int hashSize = 26;

int hashKey(char letter) {
	return letter - 'a';
}

HashTable* hashCreate() {
	HashTable* temp = malloc(sizeof(HashTable));
	temp -> fCount = 1;
	temp -> next = NULL;
	return temp;
}
void initHash(HashTable **head) {
	for(int i = 0; i < hashSize; i++) {
		head[i] = hashCreate();
	}
}

void hashInsert(HashTable *head) {
    head -> fCount++;
}

int hashSearch(HashTable *head) {
	return head -> fCount;
}

void populateHash(HashTable **head, char *word) {
    for(int i = 0; word[i]; i++) {
        hashInsert(head[hashKey(word[i])]);
    }
}

bool isAnagram(char * s, char * t){
    HashTable *sHash[hashSize], *tHash[hashSize];

    initHash(sHash);
    initHash(tHash);

    populateHash(sHash, s);
    populateHash(tHash, t);

    for(int i = 0; i < hashSize; i++) {
            if(hashSearch(sHash[i]) != hashSearch(tHash[i])) {
                return false;
            }
    }

    return true;
}

