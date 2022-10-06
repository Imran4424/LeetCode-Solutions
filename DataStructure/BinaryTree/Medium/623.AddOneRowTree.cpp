
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
	TreeNode* preOrder(TreeNode* root, int val, int depth) {
		if (NULL == root) {
			return root;
		}

		if (2 == depth) {
			// left
			TreeNode* left = new TreeNode(val);
			left -> left = root -> left;
			root -> left = left;

			// right
			TreeNode* right = new TreeNode(val);
			right -> right = root -> right;
			root -> right = right;

			return root;
		}

		root -> left = preOrder(root -> left, val, depth - 1);
		root -> right = preOrder(root -> right, val, depth - 1);
		return root;
	}

public:
	TreeNode* addOneRow(TreeNode* root, int val, int depth) {
		if (1 == depth) {
			TreeNode* left = new TreeNode(val);
			left -> left = root;
			return left;
		}

		return preOrder(root, val, depth);
	}
};