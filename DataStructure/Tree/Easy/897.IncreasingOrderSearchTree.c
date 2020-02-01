
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void InOrder(struct TreeNode* root, int *elements, int *index) {
    if(NULL == root) {
        return;
    }
    
    InOrder(root -> left, elements, index);
    elements[(*index)++] = root -> val;
    InOrder(root -> right, elements, index);
}


struct TreeNode* increasingBST(struct TreeNode* root) {
    int elements[101];
    
    int size = 0;
    InOrder(root, elements, &size);
    
    printf("%d\n", size);
    
    struct TreeNode* newHead = NULL;
    struct TreeNode* travel;
    
    for(int x = 0; x < size; x++) {
        struct TreeNode* temp = malloc(sizeof(struct TreeNode));
        temp -> val = elements[x];
        temp -> left = NULL;
        temp -> right = NULL;
        
        if(NULL == newHead) {
            newHead = temp;
            travel = newHead;
        } else {
            while(NULL != travel -> right) {
                travel = travel -> right;
            }
            
            travel -> right = temp;
        }
    }
    
    return newHead;
}