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


int minDiffInBST(struct TreeNode* root){

}