/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int high, low;

bool isDeleteAble(int num) {
	if(num < low || num > high) {
		return true;
	}

	return false;
}

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


struct TreeNode* deleteNode (struct TreeNode* root, int target) {
	if(NULL == root) {
		return root;
	}

	if(target < root -> val) {
		root -> left = deleteNode(root -> left, target);
	} else if(target > root -> val) {
		root -> right = deleteNode(root -> right, target);
	} else {
		// no child
		if(NULL == root -> left && NULL == root -> right) {
			return NULL;
		} else if(NULL == root -> left) {
			root = root -> right;
		} else if(NULL == root -> right) {
			root = root -> left;
		} else {
			// both child
			// taking the max vale from left sub tree
			int replaceVal = MaxValue(root -> left);

			root -> val = replaceVal;

			root -> left = deleteNode(root -> left, replaceVal);
		}
	}

	return root;
}

struct TreeNode* preOrderDelete(struct TreeNode* root) {
	if(NULL == root) {
		return;
	}

	if(isDeleteAble(root -> val)) {
		root = deleteNode(root, root -> val);
	}

	root -> left = preOrderDelete(root -> left);
}

struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
	high = R;
	low = L;

	return root;
}

