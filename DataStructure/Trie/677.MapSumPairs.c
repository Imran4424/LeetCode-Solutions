

const int tSize = 26;

typedef struct MapSum{
	bool endMark;
	int nodeVal;
	struct MapSum* next[26];
} MapSum;

/** Initialize your data structure here. */

MapSum* mapSumCreate() {
	MapSum* root = malloc(sizeof(MapSum));
}

void mapSumInsert(MapSum* obj, char * key, int val) {
  
}

int mapSumSum(MapSum* obj, char * prefix) {
  
}

void mapSumFree(MapSum* obj) {
    
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);
 
 * int param_2 = mapSumSum(obj, prefix);
 
 * mapSumFree(obj);
*/