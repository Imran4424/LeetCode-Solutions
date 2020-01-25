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

int MaxValue(struct TreeNode* root) {
	if(NULL == root -> right) {
		return root -> val;
	}

	return MaxValue(root -> right);
}



struct TreeNode* deleteNodeLeft(struct TreeNode* root, int target) {
	if(NULL == root) {
		return root;
	}

	if(target > root -> val) {
		root -> right = deleteNodeLeft(root -> right, target);
	} else if(target < root -> val) {
		root -> left = deleteNodeLeft(root -> left, target);
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

			root -> right = deleteNodeLeft(root -> right, replaceVal);
		}
	}

	return root;
}

struct TreeNode* deleteNodeRight(struct TreeNode* root, int target) {
	if(NULL == root) {
		return root;
	}

	if(target > root -> val) {
		root -> right = deleteNodeRight(root -> right, target);
	} else if(target < root -> val) {
		root -> left = deleteNodeRight(root -> left, target);
	} else {
		if(NULL == root -> left && NULL == root -> right) {
			root = NULL;
		} else if(NULL == root -> left) {
			root = root -> right;
		} else if(NULL == root -> right) {
			root = root -> left;
		} else {
			int replaceVal = MaxValue(root -> left);

			root -> val = replaceVal;

			root -> right = deleteNodeLeft(root -> right, replaceVal);
		}
	}

	return root;
}

struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
	if(NULL == root) {
		return root;
	}

	while(NULL != root && (root -> val < L || root -> val > R)) {
		root = deleteNodeLeft(root, root -> val);
	}

	if(NULL == root) {
		return root;
	}

	root -> left = trimBST(root -> left, L, R);
	root -> right = trimBST(root -> right, L, R);

	return root;
}

