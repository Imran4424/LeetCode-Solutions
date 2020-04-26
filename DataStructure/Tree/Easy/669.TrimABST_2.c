/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* trimBST(struct TreeNode* root, int high, int low) {
	if(NULL == root) {
		return root;
	}

	if(low < root -> val) {
		root = trimBST(root -> left, high, low);
	}

	if(high > root -> val) {
		root = trimBST(root -> right, high, low);
	}

	root -> left = trimBST(root -> left, high, low);
	root -> right =trimBST(root -> right, high, low);

	return root;
}

