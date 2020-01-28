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

    values[(*index)++] = root -> val;

    getValues(root -> left, values, index);
    getValues(root -> right, values, index);
}

int Absolute(int x) {
    if(x < 0) {
        return -x;
    }

    return x;
}

int getMinimumDifference(struct TreeNode* root) {
    int values[10001];
    int tSize = 0;
    getValues(root, values, &tSize);

    int minDiff = 32000;

    for(int i = 0; i < tSize; i++) {
        for(int j = i + 1; j < tSize; j++) {
            int diff = Absolute(values[i] - values[j]);

            if(diff < minDiff) {
                minDiff = diff;
            }
        }
    }

    return minDiff;
}

