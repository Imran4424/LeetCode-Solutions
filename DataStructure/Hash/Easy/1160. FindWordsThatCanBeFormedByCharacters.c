
typedef struct HashTable {
    int frequency;
    struct HashTable* next;
} HashTable;

const int hashSize = 26;

int hashKey(char letter) {
    return letter - 'a';
}

HashTable* createHash(HashTable* head) {
    HashTable* temp = malloc(sizeof(HashTable));
    temp -> frequency = 1;
    temp -> next = head;

    return temp;
}

HashTable* insertHash(HashTable* head) {
    if(NULL == head) {
        return createHash(head);
    }

    head -> frequency++;

    return head;
}

int searchHash(HashTable* head) {
    if(NULL == head) {
        return 0;
    }

    return head -> frequency;
}

void initHash(HashTable **head) {
    for(int i = 0; i < hashSize; i++) {
        head[i] = NULL;
    }
}


int countCharacters(char ** words, int wordsSize, char * letters){
    HashTable* head[hashSize];
    initHash(head);

    for(int i = 0; letters[i]; i++) {
        int key = hashKey(letters[i]);

        head[key] = insertHash(head[key]);
    }

    int totalLength = 0;

    for(int i = 0; i < wordsSize; i++) {
        int currentLength = 0;
        HashTable *wordHead[hashSize];
        initHash(wordHead);
        for(int j = 0; words[i][j]; j++) {
            int key = hashKey(words[i][j]);
            wordHead[key] = insertHash(wordHead[key]);

            currentLength++;
        }

        for(int x = 0; x < hashSize; x++) {
            int wordCount = searchHash(wordHead[x]);
            int letterCount = searchHash(head[x]);

            if(0 != wordCount && wordCount > letterCount) {
                currentLength = 0;
                break;
            }
        }

        totalLength += currentLength;
    }

    return totalLength;
}

