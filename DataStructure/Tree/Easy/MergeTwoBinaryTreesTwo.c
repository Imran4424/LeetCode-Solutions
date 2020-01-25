/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mergeTrees(struct TreeNode* treeOne, struct TreeNode* treeTwo) {
    if((NULL == treeOne && NULL == treeTwo) || NULL == treeTwo) {
        return treeOne;
    } else if(NULL == treeOne) {
        treeOne = treeTwo;
    } else {
        treeOne -> val = treeOne -> val + treeTwo -> val;
        
        treeOne -> left = mergeTrees(treeOne -> left, treeTwo -> left);
        treeOne -> right = mergeTrees(treeOne -> right, treeTwo -> right);
    }
    
    return treeOne;
}