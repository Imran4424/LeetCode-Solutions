

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
	bool preFind(TreeNode* root, int &target, int &pickCount) {
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
		target -= root -> val;
		++pickCount;
		bool leftPick = preFind(root -> left, target, pickCount);
		// backtracking
		target += root -> val;
		--pickCount;

		bool leftNotPick = preFind(root -> left, target, pickCount);

		// right
		target -= root -> val;
		++pickCount;
		bool rightPick = preFind(root -> right, target, pickCount);
		// backtracking
		target += root -> val;
		--pickCount;

		bool rightNotPick = preFind(root -> right, target, pickCount);

		return leftPick || leftNotPick || rightPick || rightNotPick;
	}
public:
	bool findTarget(TreeNode* root, int target) {
		int pickCount = 0;
		return preFind(root, target, pickCount);
	}
};

/*
	Still wrong answer

	need to fix later
*/