/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int tIndex;

void inOrder(struct TreeNode* root, int* values) {
	if(NULL == root) {
		return;
	}	

	inOrder(root -> left, values);

	values[tIndex++] = root -> val;

	inOrder(root -> right, values);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	tIndex = 0;

	int *values = malloc(1000 * sizeof(int));

	inOrder(root, values);

	*returnSize = tIndex;

	return values;
}