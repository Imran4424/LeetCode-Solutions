
const int hashSize = 1000;

typedef struct HashTable {
        char *word;
        int frequency;
        struct HashTable* next;
} HashTable;

int hashKey(char *word) {
        long long int asciiSum = 0;

        for(int i = 0; word[i]; i++) {
                asciiSum = (asciiSum * 10) + word[i];
        }

        return asciiSum % hasSize;
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
                head = hashNode(word);
                return head;
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

void tokenString(char *sentence, char **tokenArr, int *index, HashTable** head) {
        int x = 0;

        for(int i = 0; sentence[i]; i++) {
                if(' ' == sentence[i]) {
                        tokenArr[(*index)][x] = '\0';
                        int key = hashKey(head[key], tokenArr[(*index)]);
                        x = 0;
                        (*index)++;
                        i++;
                }       

                tokenArr[(*index)][x++] = sentence[i];
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** uncommonFromSentences(char * first, char * second, int* returnSize){
        HashTable* head[hasSize];
        initHash(head);

        int tokenSize = 40;
        
        char **firstToken = malloc(tokenSize * sizeof(char *));
        int firstIndex = 0;
        for (int i = 0; i < tokenSize; i++) {
                firstToken[i] = malloc(15 * sizeof(char));
        }
        tokenString(first, firstToken, &firstIndex, head);

        char **secondToken = malloc(tokenSize * sizeof(char *));
        int secondIndex = 0;
        for (int i = 0; i < tokenSize; i++) {
                secondToken[i] = malloc(15 * sizeof(char));
        }
        tokenString(second, secondToken, &secondIndex, head);

        char** uncommonWords = malloc(20 * sizeof(char *));
        int uIndex = 0;
        for(int i = 0; i < 20; i++) {
                uncommonWords[i] = malloc(15 * sizeof(char));
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

