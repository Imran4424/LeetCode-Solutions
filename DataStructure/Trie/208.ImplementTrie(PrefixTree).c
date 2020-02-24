
const int tSize = 26;

typedef struct Trie {
	bool endMark;
	struct Trie *next[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
	Trie* root = malloc(sizeof(Trie));

	root -> endMark = false;

	for (int i = 0; i < tSize; ++i) {
		root -> next[i] = NULL;
	}

	return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* travel, char *word) {
	if(NULL == travel) {
		travel = trieCreate();
	}

	for (int i = 0; word[i]; i++) {
		int letter = word[i] - 'a';

		if(NULL == travel -> next[letter]) {
			travel -> next[letter] = trieCreate();
		}

		travel = travel -> next[letter];
	}

	travel -> endMark = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* travel, char *word) {
	if(NULL == travel) {
		return false;
	}

    for (int i = 0; word[i]; i++) {
        int letter = word[i] - 'a';

        if(NULL == travel -> next[letter]) {
            return false;
        }

		travel = travel -> next[i];
	}

	return travel -> endMark;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* travel, char * prefix) {
	if(NULL == travel) {
		return false;
	}

	for (int i = 0; prefix[i]; i++) {
		int letter = prefix[i] - 'a';

		if(NULL == travel -> next[letter]) {
			return false;
		}

		travel = travel -> next[letter];
	}

	for(int i = 0 ; i < tSize; i++) {
		if(NULL != travel -> next[i]) {
			return true;
		}
	}

	return travel -> endMark;
}

void trieFree(Trie* obj) {
	free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/