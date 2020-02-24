

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
		
	}
}

int mapSumSum(MapSum* obj, char * prefix) {
  
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