
const int tSize = 26;

typedef struct WordDictionary {
	bool endMark;
	struct WordDictionary *next[26];
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
	WordDictionary *root = malloc(sizeof(WordDictionary));
	root -> endMark = false;

	for(int i = 0; i < tSize; i++) {
		root -> next[i] = NULL;
	}

	return root;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* travel, char * word) {
	if(NULL == travel) {
		travel = wordDictionaryCreate();
	}

	for (int i = 0; word[i]; i++) {
		int letter = word[i] - 'a';

		if(NULL == travel -> next[letter]) {
			travel -> next[letter] = wordDictionaryCreate();
		}

		travel = travel -> next[letter];
	}

	travel -> endMark = true;
}

void copyStringExclude(char *dest, char *source, int index) {
	int i = 0;
	for (; source[index]; i++) {
		dest[i] = source[index++];
	}

	dest[i] = '\0';
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* travel, char * word) {
	if(NULL == travel) {
		return false;
	}

	int i;
	for (i = 0; word[i]; i++) {
		if('.' == word[i]) {
			
			char transWord[15];
			copyStringExclude(transWord, word, i + 1);

			for(int index = 0; index < tSize; index++) {
				if(NULL != travel -> next[index]) {
					if(wordDictionarySearch(travel -> next[index], transWord)) {
						return true;
					}	
				}
			}

			
			return false;
		}

		int letter = word[i] - 'a';

		if(NULL == travel -> next[letter]) {
			return false;
		}

		travel = travel -> next[letter];
	}

	
	return travel -> endMark;
}

void wordDictionaryFree(WordDictionary* travel) {
	free(travel);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/