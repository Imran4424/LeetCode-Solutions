/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int SortedOrder(struct TreeNode* root, int low , int high, int currentSum) {
    if(NULL == root) {
        return currentSum;
    }
    
    currentSum = SortedOrder(root -> left, low, high, currentSum);
    
    //printf("%d ", root -> val);
         
    if(root -> val <= high) {
        
        if(root -> val >= low) {
            currentSum = currentSum + root -> val;
        }
        
        currentSum = SortedOrder(root -> right, low, high, currentSum);
    }
    
    return currentSum;
}

int rangeSumBST(struct TreeNode* root, int L, int R){
    return SortedOrder(root, L, R, 0);
}