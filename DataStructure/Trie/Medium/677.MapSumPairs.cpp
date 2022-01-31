/*
	Design a map that allows you to do the following:

	Maps a string key to a given value.
	Returns the sum of the values that have a key with a prefix equal to a given string.

	Implement the MapSum class:

	MapSum() Initializes the MapSum object.
	void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, 
	the original key-value pair will be overridden to the new one.
	int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

 

	Example 1:

	Input
	["MapSum", "insert", "sum", "insert", "sum"]
	[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
	Output
	[null, null, 3, null, 5]

	Explanation
	MapSum mapSum = new MapSum();
	mapSum.insert("apple", 3);  
	mapSum.sum("ap");           // return 3 (apple = 3)
	mapSum.insert("app", 2);    
	mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)

 

	Constraints:

	1 <= key.length, prefix.length <= 50
	key and prefix consist of only lowercase English letters.
	1 <= val <= 1000
	At most 50 calls will be made to insert and sum.
*/

class MapSum {
	struct Node
	{
		int value;
		Node *next[26];


		Node() {
			value = 0;
			for (int i = 0; i < 26; i++) {
				next[i] = NULL;
			}
		}
	};

	Node *root;
	int prefixSum;

	void findAllSum(Node *travel) {
		if (travel->value > 0) {
			prefixSum += travel->value;
		}

		for (int i = 0; i < 26; i++) {
			if (NULL != travel->next[i]) {
				findAllSum(travel->next[i]);
			}
		}
	}

public:
	MapSum() {
		root = new Node();
	}

	void insert(string key, int val) {
		Node* travel = root;

		for (int i = 0; key[i]; i++) {
			int letter = key[i] - 'a';

			if (NULL == travel->next[letter]) {
				travel->next[letter] = new Node();
			}

			travel = travel -> next[letter];
		}

		travel->value = val;
	}

	int sum(string prefix) {
		Node* travel = root;

		for (int i = 0; prefix[i]; i++) {
			int letter = prefix[i] - 'a';

			if (NULL == travel->next[letter]) {
				return 0;
			}

			travel = travel -> next[letter];
		}

		prefixSum = 0;
		findAllSum(travel);

		return prefixSum;
	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */