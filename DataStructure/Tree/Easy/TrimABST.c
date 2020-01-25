/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int MinValue(struct TreeNode* root) {
	if(NULL == root -> left) {
		return root -> val;
	}

	return MinValue(root -> left);
}

struct TreeNode* trimBST(struct TreeNode* root, int L, int R){

}

