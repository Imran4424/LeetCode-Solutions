/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef long long int lli;

lli tIndex;

void getValues(struct TreeNode* root, lli* values) {
	if(NULL == root) {
		return;
	}

	values[tIndex++] = root -> val;

	getValues(root -> left, values);
	getValues(root -> right, values);
}

lli Absolute(lli x) {
	if(x < 0) {
		return -x;
	}

	return x;
}

int minDiffInBST(struct TreeNode* root){
	tIndex = 0;

	lli *values = malloc(1000 * sizeof(lli));

	getValues(root, values);

	lli minDiff = 32000;

	for(lli i = 0; i < values; i++) {
		for(lli j = i + 1; j < values; j++) {
			lli currentDiff = Absolute(values[i] - values[j]);

			if(currentDiff < minDiff) {
				minDiff = currentDiff;
			}
		}
	}

	return minDiff;
}