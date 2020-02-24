
const int tSize = 26;

typedef struct Trie {
	bool endMark;
	int frequency;
	struct Trie *next[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
	Trie* root = malloc(sizeof(Trie));

	root -> endMark = false;
	frequency = 0;

	for (int i = 0; i < tSize; ++i) {
		root -> next[i] = NULL;
	}

	return root;
}

int maxFrequency;

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
	travel -> frequency += 1;

	if(travel -> frequency > maxFrequency) {
		maxFrequency = travel -> frequency;
	}
}

void copyString(char *dest, char *source) {
    int i;
    for(i = 0; source[i]; i++) {
        dest[i] = source[i];
    }

    dest[i] = '\0';
}

char **frequentWords;
int indexTrie;

void findFrequentWords(node* travel, char *word, int pos) {
    if(NULL == travel) {
        return;
    }

    if(travel -> endMark && travel -> frequency == maxFrequency) {
        word[pos] = '\0';
        word = reverseString(word, pos);
        copyString(arrTrie[indexTrie++], word);
    }

    for (int i = 0; i < tSize; ++i)
    {
        if(travel -> next[i]) {
            word[pos] = i + 'a';

            findFrequentWords(travel -> next[i], word, pos + 1);
        }
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
	maxFrequency = 0;
	indexTrie = 0;
	Trie* root = trieCreate();

	frequentWords = malloc(wordsSize * sizeof(char));
	for(int i = 0; i < wordsSize; i++) {
		frequentWords[i] = malloc(15 * sizeof(char));

		trieInsert(root, words[i]);
	}

	char temp[15];
	findFrequentWords(root, temp, 0);

	*returnSize = k;

	return frequentWords;
}

