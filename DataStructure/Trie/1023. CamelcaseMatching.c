

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char ** queries, int queriesSize, char * pattern, int* returnSize){
	bool *arr = malloc(queriesSize * sizeof(bool));

	int pIndex = 0, bIndex = 0;
	for (int i = 0; i < queriesSize; i++) {
		
		bool status = true;
		for (int x = 0; queries[i][x]; x++) {
			if(queries[x][i] >= 'A' && queries[i][x] <= 'Z') {
				if(queries[x][i] != pattern[pIndex]) {
					status = false;
					break;
				} else {
					pIndex++;
				}
			}
		}

		arr[bIndex++] = status;
	}

	*returnSize = queriesSize;

	return arr;
}

