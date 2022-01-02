/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	bool isSameTree(TreeNode* treeOne, TreeNode* treeTwo) {
		if (NULL == treeOne || NULL == treeTwo) {
			if (treeOne == treeTwo) {
				return true;
			}

			return false;
		}

		if (treeOne->val != treeTwo->val) {
			return false;
		}

		return isSameTree(treeOne->left, treeTwo->right) && isSameTree(treeOne->right, treeTwo->left);
	}

public:
	bool isSymmetric(TreeNode* root) {
		return isSameTree(root->left, root->right);
	}
};