/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getValue(struct TreeNode* root, int *data, int *index) {
	if(NULL == root) {
	return;
	}

	data[(*index)++] = root -> val;

	getValue(root -> left, data, index);
	getValue(root -> right, data, index);
}

bool findTarget(struct TreeNode* root, int k) {
	int data[10001];
	int dSize = 0;

	getValue(root, data, &dSize);

	for(int i = 0; i < dSize; i++) {
		for(int j = i + 1; j < dSize; j++) {
			if(data[i] + data[j] == k) {
				return true;
			}
		}
	}

	return false;
}

