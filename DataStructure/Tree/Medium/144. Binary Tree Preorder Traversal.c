/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int tIndex;

void preOrder(struct TreeNode* root, int* values) {
	if(NULL == root) {
		return;
	}

	values[tIndex++] = root -> val;
	
	preOrder(root -> left, values);
	preOrder(root -> right, values);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	tIndex = 0;

	int *values = maloc(1000 * sizeof(int));

	preOrder(root, values);

	*returnSize = tIndex;

	return values;
}