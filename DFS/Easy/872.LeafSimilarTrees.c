/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

void getLeafNodes(struct TreeNode* root, int *leaf, int *index) {
    if(NULL == root) {
        return;
    }
    
    if(NULL == root -> left && NULL == root -> right) {
        leaf[(*index)++] = root -> val; 
        
        return;
    }
    
    getLeafNodes(root -> left, leaf, index);
    getLeafNodes(root -> right, leaf, index);
}

bool leafSimilar(struct TreeNode* rootOne, struct TreeNode* rootTwo) {
    int leftLeaf[100];
    int rightLeaf[100];
    int leftSize = 0, rightSize = 0;
    
    getLeafNodes(rootOne, leftLeaf, &leftSize);
    getLeafNodes(rootTwo, rightLeaf, &rightSize);
    
    int i, j;
    for(i = 0, j = 0; i < leftSize && j < rightSize; i++, j++) {
        if(leftLeaf[i] != rightLeaf[j]) {
            return false;
        }
    }
    
    return true;
}