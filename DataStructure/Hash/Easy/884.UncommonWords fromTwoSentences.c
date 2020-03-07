
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

int compareString(char *subject, char *)

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
                if()
        }
}

void initHash(HashTable** head) {
        for(int i = 0; i < hashSize; i++) {
                head[i] = NULL;
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** uncommonFromSentences(char * first, char * second, int* returnSize){

}

