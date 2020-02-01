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

void Init(double *levelSum, double *levelCount, int treeDepth) {
    for(int i = 0; i < treeDepth; i++){
        levelSum[i] = 0.0;
        levelCount[i] = 0.0;

        //printf("%lf %lf\n", levelSum[i], levelCount[i]);
    }
}

void findLevelSum(struct TreeNode* root, double *levelSum, double *levelCount, int index) {
    if(NULL == root) {
        return;
    }

    levelSum[index] = levelSum[index] + root -> val;
    levelCount[index]++;
    index++;

    findLevelSum(root -> left, levelSum, levelCount, index);
    findLevelSum(root -> right, levelSum, levelCount, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    int treeDepth = 0;
    findDepth(root, &treeDepth, 0);

    double levelSum[treeDepth], levelCount[treeDepth];
    Init(levelSum, levelCount, treeDepth);
    findLevelSum(root, levelSum, levelCount, 0);

    double *levelAverage = malloc(treeDepth * sizeof(double));

    for(int i = 0; i < treeDepth; i++) {
        levelAverage[i] = levelSum[i] / levelCount[i];
    }

    *returnSize = treeDepth;
    return levelAverage;
}


