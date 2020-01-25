
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isUnique(struct TreeNode* root, int target) {
    if(NULL == root) {
        return true;
    }
    
    if(target != root -> val) {
        return false;
    }
    
    bool left = isUnique(root -> left, target);
    bool right = isUnique(root -> right, target);
    
    if(left && right) {
        return true;
    }
    
    return false;
}


bool isUnivalTree(struct TreeNode* root) {
    return isUnique(root, root -> val);
}