
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

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* travel, char * word) {
	if(NULL == travel) {
		return false;
	}

	int i;
	for (i = 0; word[i]; i++) {
		if('.' == word[i]) {
			bool found = false;

			char 

			for(int index = 0; index < tSize; index++) {
				if(NULL != travel -> next[index]) {
					found = true;
					travel = travel -> next[index];
					break;
				}
			}

			if(found) {
				continue;
			}

			return false;
		}

		int letter = word[i] - 'a';

		if(NULL == travel -> next[letter]) {
			return false;
		}

		travel = travel -> next[letter];
	}

	if('.' == word[i - 1]) {
		return true;
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