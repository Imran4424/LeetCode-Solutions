
const int hashSize = 1000;

typedef struct HashTable {
        char word[20];
        int frequency;
        struct HashTable* next;
} HashTable;

HashTable **head;

int hashKey(char *word) {
        long long int asciiSum = 0;

        for(int i = 0; word[i]; i++) {
                asciiSum = (asciiSum * 10) + word[i];
        }

        return asciiSum % hashSize;
}

void copyString(char *destination, char *source) {
        int i;
        for (i = 0; source[i]; i++) {
                destination[i] = source[i];
        }

        destination[i] = '\0';
}

int compareString(char *subject, char *compWord) {
        int i;
        for(i = 0; subject[i]; i++) {
                if(subject[i] != compWord[i]) {
                        break;
                }
        }

        return subject[i] - compWord[i];
}

HashTable* hashNode(char *word) {
        HashTable *temp = malloc(sizeof(HashTable));
        copyString(temp -> word, word);
        temp -> frequency = 1;
        temp -> next = NULL;

        return temp;
}

HashTable* insertHash(HashTable *head, char *word) {
        if(NULL == head) {
                return hashNode(word);
        }

        HashTable* travel = head;
        HashTable* previous = NULL;

        while(NULL != travel) {
                if(0 == compareString(head -> word, word)) {
                        travel -> frequency++;
                        return head;
                }

                previous = travel;
                travel = travel -> next;
        }

        previous -> next = hashNode(word);
        return head;
}

int searchHash(HashTable* travel, char *word) {

        while(NULL != travel) {
                if(0 == compareString(travel -> word, word)) {
                        return travel -> frequency;
                }

                travel = travel -> next;
        }

        return 0;
}

void initHash(HashTable** head) {
        for(int i = 0; i < hashSize; i++) {
                head[i] = NULL;
        }
}

void tokenString(char *sentence, char **tokenArr, int *index) {
        int x = 0, key;

        for(int i = 0; sentence[i]; i++) {
                if(' ' == sentence[i]) {
                        tokenArr[(*index)][x] = '\0';
                        key = hashKey(tokenArr[(*index)]);
                        //printf("%d %s\n", key, tokenArr[(*index)]);
                        head[key] = insertHash(head[key], tokenArr[(*index)]);
                        x = 0;
                        (*index)++;
                        continue;
                }       

                tokenArr[(*index)][x++] = sentence[i];
        }

        tokenArr[(*index)][x] = '\0';
        key = hashKey(tokenArr[(*index)]);
        //printf("%d %s\n", key, tokenArr[(*index)]);
        head[key] = insertHash(head[key], tokenArr[(*index)]);
        (*index)++;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** uncommonFromSentences(char * first, char * second, int* returnSize){
        head = malloc(hashSize * sizeof(HashTable*));
        initHash(head);

        int tokenSize = 100;
        
        char **firstToken = malloc(tokenSize * sizeof(char *));
        int firstIndex = 0;
        for (int i = 0; i < tokenSize; i++) {
                firstToken[i] = malloc(20 * sizeof(char));
        }
        tokenString(first, firstToken, &firstIndex);

        char **secondToken = malloc(tokenSize * sizeof(char *));
        int secondIndex = 0;
        for (int i = 0; i < tokenSize; i++) {
                secondToken[i] = malloc(20 * sizeof(char));
        }
        tokenString(second, secondToken, &secondIndex);

        char** uncommonWords = malloc(tokenSize * sizeof(char *));
        int uIndex = 0;
        for(int i = 0; i < tokenSize; i++) {
                uncommonWords[i] = malloc(20 * sizeof(char));
        }

        for(int i = 0; i < firstIndex; i++) {
                int key = hashKey(firstToken[i]);
                if(1 == searchHash(head[key] ,firstToken[i])) {
                        copyString(uncommonWords[uIndex++], firstToken[i]);
                }
        }

        for(int i = 0 ; i < secondIndex; i++) {
                int key = hashKey(secondToken[i]);
                if(1 == searchHash(head[key], secondToken[i])) {
                        copyString(uncommonWords[uIndex++], secondToken[i]);
                }
        }

        *returnSize = uIndex;
        return uncommonWords;
}

