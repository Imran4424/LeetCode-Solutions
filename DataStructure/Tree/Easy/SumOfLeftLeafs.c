/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getleftLeafSum(struct TreeNode* root, int *leftLeafSum) {
	if(NULL == root) {
		return;
	}

	if(NULL == root -> left && NULL == root -> right) {
		*leftLeafSum = *leftLeafSum + root -> val;
		return;
	}

	getleftLeafSum(root -> left, leftLeafSum);

	if(NULL != root -> right -> left) {
		getleftLeafSum(root -> right, leftLeafSum);
	}
}

int sumOfLeftLeaves(struct TreeNode* root){

}

