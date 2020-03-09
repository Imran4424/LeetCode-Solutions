
const int hashSize = 26;
int currLength;

void countFrequency(int *frequency, char *word) {
        for(int i = 0; word[i]; i++) {
                currLength++;
                frequency[word[i] - 'a']++;
        }
}

void initHash(int *frequency) {
        for(int i = 0; i < hashSize; i++) {
                frequency[i] = 0;
        }
}

int countCharacters(char ** words, int wordsSize, char * letters) {
        int letterFrequency[hashSize];
        initHash(letterFrequency);
        countFrequency(letterFrequency, letters);

        int totalLength = 0;

        for(int i = 0; i < wordsSize; i++) {
                currLength = 0;
                int wordFrequency[hashSize];
                initHash(wordFrequency);
                countFrequency(wordFrequency, words[i]);

                for(int i = 0; i < hashSize; i++) {
                        if(letterFrequency[i] < wordFrequency[i]) {
                                currLength = 0;
                                break;
                        }
                }

                totalLength += currLength;
        }

        return totalLength;
}

