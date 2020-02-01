
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if(NULL == root) {
        return root;
    }
    
    if(val == root -> val) {
        return root;
    }
    
    struct TreeNode* leftSubTree = searchBST(root -> left, val);
    struct TreeNode* rightSubTree = searchBST(root -> right, val);
    
    if((NULL == leftSubTree && NULL == rightSubTree) || NULL == rightSubTree) {
        return leftSubTree;
    } else if(NULL == leftSubTree)  {
        return rightSubTree;
    }
    
    return NULL;
}