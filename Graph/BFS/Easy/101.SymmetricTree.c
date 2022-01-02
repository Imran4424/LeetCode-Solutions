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
        values[(*index)++] = -11;
        return;
    }

    values[(*index)++] = root -> val;

    getValues(root -> left, values, index);
    getValues(root -> right, values, index);
}

void invert(struct TreeNode* root) {
    if(NULL == root) {
        return;
    }
    /// swapping left, right child
    struct TreeNode* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;

    invert(root -> left);
    invert(root -> right);
}

bool isSymmetric(struct TreeNode* root){
    int values[10001], invertValues[10001];
    int index = 0, invertIndex = 0;

    getValues(root, values, &index);
    invert(root);
    getValues(root, invertValues, &invertIndex);

    for(int i = 0; i < index; i++) {
        if(values[i] != invertValues[i]) {
            return false;
        }
    }

    return true;
}

