

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
	bool preFind(TreeNode* root, int target, int pickCount) {
		if (2 == pickCount) {
			if (0 == target) {
				return true;
			}

			return false;
		}

		if (NULL == root) {
			if (2 == pickCount) {
				if (0 == target) {
					return true;
				}
			}

			return false;
		}

		// left
		bool leftPick = preFind(root -> left, target - root -> val, pickCount + 1);
		bool leftNotPick = preFind(root -> left, target, pickCount);

		// right
		bool rightPick = preFind(root -> right, target - root -> val, pickCount + 1);
		bool rightNotPick = preFind(root -> right, target, pickCount);

		return leftPick || leftNotPick || rightPick || rightNotPick;
	}
public:
	bool findTarget(TreeNode* root, int target) {
		return preFind(root, target, 0);
	}
};

/*
	Still wrong answer

	need to fix later
*/