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
    vector <vector<int>> paths;
    int target;
    
    void findTargetPath(TreeNode* root, int currSum, vector<int> path) {
        if(NULL == root) {
            return;
        }

        currSum = currSum + root -> val;
        path.push_back(root -> val);

        if(NULL == root -> left && NULL == root -> right) {
            if(currSum == target) {
                paths.push_back(path);
            }

            return;
        }

        if (NULL != root -> left) {
            findTargetPath(root -> left, currSum, path);
        }

        if (NULL != root -> right) {
            findTargetPath(root -> right, currSum, path);
        }
    }
    
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (NULL == root) {
            return paths;
        }

        target = targetSum;

        findTargetPath(root, 0, vector <int> ());

        return paths;
    }
};