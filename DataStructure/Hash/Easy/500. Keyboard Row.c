
int rowCheck(char letter) {
        if(letter >= 'A' && letter <= 'Z') {
                letter = letter + 32;
        }

        if('z' == letter || 'x' == letter || 'c' == letter || 'v' == letter || 'b' == letter || 'n' == letter || 'm' == letter) {
                return 2;
        } else if('a' == letter || 's' == letter || 'd' == letter || 'f' == letter || 'g' == letter || 'h' == letter || 'j' == letter || 'k' == letter || 'l' == letter) {
                return 1;
        } 

        return 0;
}

bool isInSameRow(char *word) {
        int wordRow = rowCheck(word[0]);
        
        for(int i = 1; word[i]; i++) {
                if(wordRow != rowCheck(word[i])) {
                        return false;
                }
        }

        return true;
}

void copyString(char *destination, char *source) {
        int i;
        for(i = 0; source[i]; i++) {
                destination[i] = source[i];
        }

        destination[i] = '\0';
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize){
        char **sameRowWords = malloc(wordsSize * sizeof(char *));
        int index = 0;

        for(int i = 0; i < wordsSize; i++) {
                sameRowWords[i] = malloc(50 * sizeof(char));

                if(isInSameRow(words[i])) {
                        copyString(sameRowWords[index++], words[i]);
                }
        }

        *returnSize = index;
        return sameRowWords;
}

