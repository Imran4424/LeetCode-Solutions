
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void treeSum(struct TreeNode* root, int *sum, int singleSum) {
    if(NULL == root) {
        return;
    }
    
    singleSum = (singleSum * 2) + root -> val;
    
    if(NULL == root -> left && NULL == root -> right) {
        *sum = *sum + singleSum;
        
        return;
    }
    
    
    treeSum(root -> left, sum, singleSum);
    treeSum(root -> right, sum, singleSum);
}

int sumRootToLeaf(struct TreeNode* root) {
    int sum = 0;
    
    treeSum(root, &sum, 0);
    
    return sum;
}