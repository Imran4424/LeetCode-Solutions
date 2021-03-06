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

struct TreeNode* deleteNode(struct TreeNode* root, int target) {
	if(NULL == root) {
		return root;
	}

	if(target > root -> val) {
		root -> right = deleteNode(root -> right, target);
	} else if(target < root -> val) {
		root -> left = deleteNode(root -> left, target);
	} else {
		if(NULL == root -> left && NULL == root -> right) {
			root = NULL;
		} else if(NULL == root -> left) {
			root = root -> right;
		} else if(NULL == root -> right) {
			root = root -> left;
		} else {
			int replaceVal = MinValue(root -> right);

			root -> val = replaceVal;

			root -> right = deleteNode(root -> right, replaceVal);
		}
	}

	return root;
}