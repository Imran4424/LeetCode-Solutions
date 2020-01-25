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
		target -> right = deleteNode(root -> right, target);
	} else if(target < root -> val) {
		target -> left = deleteNode(root -> left, target);
	} else {
		if(NULL == root -> left && NULL == root -> right) {
			root = NULL;
		} else if(NULL == tree -> left) {
			root = root -> right;
		} else if(NULL == tree -> right) {
			root = root -> left;
		} else {
			int replaceVal = MinValue(root -> right);

			root -> val = replaceVal;

			root -> right = deleteNode(root -> right, replaceVal);
		}
	}

	return root;
}

struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
	if(NULL == root) {
		return root;
	}

	if(root -> val > L || root -> val < R) {
		root = deleteNode(root, root -> val);
	}

	root -> left = trimBST(root -> left, L, R);
	root -> right = trimBST(root -> right, L, R);

	return root;
}

