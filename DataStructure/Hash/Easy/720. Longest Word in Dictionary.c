
void copyString(char *dest, char *source) {
    int i;
    for(i = 0; source[i]; i++) {
        dest[i] = source[i];
    }

    dest[i] = '\0';
}

int compareString(char *source, char *destination) {
    int i;
    for(i = 0; source[i] && destination[i]; i++) {
        if(source[i] != destination[i]) {
            return source[i] - destination[i];
        }
    }

    return source[i] - destination[i];
}

typedef struct node {
    bool endMark;
    struct node *next[26];
    int length;
} node;

node* root;

void trieInit() {
    root = malloc(sizeof(node));

    root -> endMark = false;
    for(int k = 0; k < 26; k++) {
        root -> next[k] = NULL;
    }
    root -> length = 0;
}



bool searchTrie(char *word) {
    node* travel = root;

    for(int i = 0; word[i]; i++) {
        int letter = word[i] - 'a';

        if(NULL == travel -> next[letter]) {
            return false;
        }

        travel = travel -> next[letter];
    }

    return travel -> endMark;
}

void trieInsertion(char *word) {
    node* travel = root;

    for(int i = 0; word[i]; i++) {
        int letter = word[i] - 'a';

        if(NULL == travel -> next[letter]) {
            travel -> next[letter] = malloc(sizeof(node));
            travel -> next[letter] -> endMark = false;
            travel -> next[letter] -> length = travel -> length + 1;
            for(int k = 0; k < 26; k++) {
                travel -> next[letter] -> next[k] = NULL;
            }
        }
        travel = travel -> next[letter];
    }
    /// marking the letters end point
    travel -> endMark = true;
}

int stringLength(char *word) {
    int len = 0;
    for(int i = 0; word[i]; i++) {
        len++;
    }

    return len;
}

char* longestWord(char **words, int wordsSize){

    trieInit();
    int maxSize = 0;
    char *maxLengthWord = malloc(32 * sizeof(char));

    for(int i = 0; i < wordsSize; i++) {
        trieInsertion(words[i]);
    }

    for(int i = 0; i < wordsSize; i++) {
        int wordlen = stringLength(words[i]);

        if(wordlen > maxSize ||(wordlen == maxSize && compareString(maxLengthWord, words[i]) > 0)) {

            char temp[30];
            bool flag = false;
            for(int index = 0; words[i][index + 1]; index++) {
                temp[index] = words[i][index];
                temp[index + 1] = '\0';

                if(!searchTrie(temp)) {
                    flag = true;
                    break;
                }
                //printf("Hi %s\n", maxLengthWord);
            }

            if(flag) {
                continue;
            }

            maxSize = wordlen;
            copyString(maxLengthWord, words[i]);
        }
    }

    return maxLengthWord;
}

