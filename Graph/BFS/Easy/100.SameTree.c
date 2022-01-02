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


bool isSameTree(struct TreeNode* oneRoot, struct TreeNode* twoRoot) {
    int oneValues[1001], twoValues[1001];
    int oneSize = 0, twoSize = 0;

    getValues(oneRoot, oneValues, &oneSize);
    getValues(twoRoot, twoValues, &twoSize);

    int i, j;

    for(i = 0, j = 0; i < oneSize && j < twoSize; i++, j++) {
        if(oneValues[i] != twoValues[j]) {
            return false;
        }
    }

    if(i != oneSize || j != twoSize) {
        return false;
    }

    return true;
}

