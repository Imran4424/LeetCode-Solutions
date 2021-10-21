
const int hashSize = 26;

void findFrequency(int *frequency, char *word) {
        for(int i = 0 ; i < hashSize; i++) {
                frequency[i] = 0;
        }
        
        for(int i = 0; word[i]; i++) {
                frequency[word[i] - 'a']++;
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
        int letterFrequency[wordsSize][hashSize];

        for (int i = 0; i < wordsSize; i++) {
                findFrequency(letterFrequency[i], words[i]);
        }

        char **commonLetters =  malloc( 501 * sizeof(char*));
        for(int x = 0; x < 501; x++) {
                commonLetters[x] = malloc(2 * sizeof(char));
        }

        int index = 0;

        for(int i = 0; i < hashSize; i++) {
                int minCount = 1000;
                for (int k = 0 ; k < wordsSize; k++) {
                        if(letterFrequency[k][i] < minCount) {
                                minCount = letterFrequency[k][i];
                        }

                        if(0 == minCount) {
                                break;
                        }
                }

                while(minCount--) {
                        commonLetters[index][0] = i + 'a';
                        commonLetters[index][1] = '\0';
                        index++;
                }
        }

        *returnSize = index;
        return commonLetters;
}

