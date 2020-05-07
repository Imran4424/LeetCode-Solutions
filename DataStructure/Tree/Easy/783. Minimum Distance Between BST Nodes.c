/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int tIndex;

void getValues(struct TreeNode* root, int* values) {
	if(NULL == root) {
		return;
	}

	values[tIndex++] = root -> val;

	getValues(root -> left, values);
	getValues(root -> right, values);
}

int Absolute(int x) {
	if(x < 0) {
		return -x;
	}

	return x;
}

int minDiffInBST(struct TreeNode* root){
	tIndex = 0;

	int *values = malloc(1000 * sizeof(int));

	getValues(root, values);

	int minDiff = 32000;

	for(int i = 0; i < values; i++) {
		for(int j = i + 1; j < values; j++) {
			int currentDiff = Absolute(values[i] - values[j]);

			if(currentDiff < minDiff) {
				minDiff = currentDiff;
			}
		}
	}

	return minDiff;
}