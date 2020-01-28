/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getleftLeafSum(struct TreeNode* root, int *leftLeafSum, int rootCount) {
	if(NULL == root) {
		return;
	}

	rootCount++;

	if(NULL == root -> left && NULL == root -> right && rootCount > 1) {
		*leftLeafSum = *leftLeafSum + root -> val;
		return;
	}

	getleftLeafSum(root -> left, leftLeafSum);

	if(NULL != root -> right -> left) {
		getleftLeafSum(root -> right, leftLeafSum, 0);
	}
}

int sumOfLeftLeaves(struct TreeNode* root){
	int leftLeafSum = 0;

	getleftLeafSum(root, &leftLeafSum);

	return leftLeafSum;
}

