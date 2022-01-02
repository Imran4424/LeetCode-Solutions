/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void findDepth(struct TreeNode* root, int *mDepth, int currentDepth) {
    if(NULL == root) {
        return;
    }
    
    currentDepth++;
    
    if(NULL == root -> left && NULL == root -> right) {
        if(currentDepth > *mDepth) {
            *mDepth = currentDepth;
            
            return;
        }
    }
    
    findDepth(root -> left, mDepth, currentDepth);
    findDepth(root -> right, mDepth, currentDepth);
}

int maxDepth(struct TreeNode* root){
    int treeDepth = 0;
    
    findDepth(root, &treeDepth, 0);
    
    return treeDepth;
}

