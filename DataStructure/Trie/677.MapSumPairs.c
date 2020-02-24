

const int tSize = 26;

typedef struct MapSum{
	bool endMark;
	int nodeVal;
	struct MapSum* next[26];
} MapSum;

/** Initialize your data structure here. */

MapSum* mapSumCreate() {
	MapSum* root = malloc(sizeof(MapSum));
	root -> endMark = false;
	root -> nodeVal = 0;
	for (int i = 0; i < tSize; i++) {
		root -> next[i] = NULL;
	}

	return root;
}

void mapSumInsert(MapSum* travel, char * key, int val) {
	if(NULL == travel) {
		travel = mapSumCreate();
	}

	for(int i = 0; key[i]; i++) {
		int letter = key[i] - 'a';

		if(NULL == travel -> next[letter]) {
			travel -> next[letter] = mapSumCreate();
		}

		travel = travel -> next[letter];
	}

	travel -> endMark = true;
	travel -> nodeVal = val;
}

int findMapSum(MapSum* travel) {
	if(NULL == travel) {
		return 0;
	}

	int sum = travel -> nodeVal;

	for(int i = 0; i < tSize; i++) {
		if(NULL != travel -> next[i]) {
			sum += findMapSum(travel -> next[i]);
		}
	}

	return sum;
}

int mapSumSum(MapSum* travel, char * prefix) {
	if(NULL == travel) {
		return 0;
	}

	for(int i = 0; prefix[i]; i++) {
		int letter = prefix[i] - 'a';

		if(NULL == travel -> next[letter]) {
			return 0;
		}

		travel = travel -> next[letter];
	}

	int sum = travel -> nodeVal;

	for(int i = 0; i < tSize; i++) {
		if(NULL != travel -> next[i]) {
			sum += findMapSum(travel -> next[i]);
		}
	}

	return sum;
}

void mapSumFree(MapSum* travel) {
	free(travel);
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);
 
 * int param_2 = mapSumSum(obj, prefix);
 
 * mapSumFree(obj);
*/