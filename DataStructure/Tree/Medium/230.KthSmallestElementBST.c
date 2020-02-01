/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getValues(struct TreeNode* root, int *values, int *index) {
    if(NULL == root) {
        return;
    }

    getValues(root -> left, values, index);
    values[(*index)++] = root -> val;
    getValues(root -> right, values, index);
}



int kthSmallest(struct TreeNode* root, int k){
    int values[10001];
    int index = 0;

    getValues(root, values, &index);

    return values[k - 1];
}