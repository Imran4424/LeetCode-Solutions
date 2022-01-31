/*
	Design a data structure that supports adding new words and finding if a string matches any 
	previously added string.

	Implement the WordDictionary class:

	    WordDictionary() Initializes the object.
	    
	    void addWord(word) Adds word to the data structure, it can be matched later.
	    
	    bool search(word) Returns true if there is any string in the data structure that matches word 
	    or false otherwise. word may contain dots '.' where dots can be matched with any letter.


	Example:

	Input
	["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
	[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
	Output
	[null,null,null,null,false,true,true,true]

	Explanation
	WordDictionary wordDictionary = new WordDictionary();
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	wordDictionary.search("pad"); // return False
	wordDictionary.search("bad"); // return True
	wordDictionary.search(".ad"); // return True
	wordDictionary.search("b.."); // return True

	Constraints:

	    1 <= word.length <= 500
	    word in addWord consists lower-case English letters.
	    word in search consist of  '.' or lower-case English letters.
	    At most 50000 calls will be made to addWord and search.
*/

class WordDictionary {
	struct Node
	{
		bool endMark;
		Node *next[26];

		Node() {
			endMark = false;
			for (int i = 0; i < 26; i++) {
				next[i] = NULL;
			}
		}		
	};

	Node *root;
	string givenWord;
	bool isFound;

	void findWord(Node *travel, int index) {
		if (isFound || NULL == travel) {
			return;
		}

		if (index == givenWord.size()) {
			if (travel->endMark) {
				isFound = true;
			}

			return;
		}
		

		if ('.' == givenWord[index]) {
			for (int i = 0; i < 26; i++) {
				if (NULL != travel->next[i]) {
					findWord(travel->next[i], index + 1);
				}
			}
		} else {
			int letter = givenWord[index] - 'a';

			if (NULL != travel->next[letter]) {
				findWord(travel->next[letter], index + 1);
			}
		}
	}

public:
	WordDictionary() {
		root = new Node();
	}

	void addWord(string word) {
		Node *travel = root;

		for (int i = 0; word[i]; i++) {
			int letter = word[i] - 'a';

			if (NULL == travel->next[letter]) {
				travel->next[letter] = new Node();
			}

			travel = travel->next[letter];
		}

		travel->endMark = true;
	}

	bool search(string word) {
		givenWord = word;
		isFound = false;

		findWord(root, 0);

		return isFound;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */