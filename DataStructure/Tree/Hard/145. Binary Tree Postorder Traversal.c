/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int tIndex;

void postOrder(struct TreeNode* root, int* values) {
	if(NULL == root) {
		return;
	}

	postOrder(root -> left, values);
	postOrder(root -> right, values);

	values[tIndex++] = root -> val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	tIndex = 0;

	int *values = malloc(1000 * sizeof(int));

	postOrder(root, values);

	*returnSize = tIndex;

	return values;
}