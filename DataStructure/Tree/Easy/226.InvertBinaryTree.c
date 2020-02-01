
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root) {
    if(NULL == root) {
        return root;
    }
    
    struct TreeNode *temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    
    root -> left = invertTree(root -> left);
    root -> right = invertTree(root -> right);
    
    return root;
}

