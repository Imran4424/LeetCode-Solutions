/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

char *nodeStr;
int strIndex;

void treeToString(struct TreeNode* root) {
	if(NULL == root) {
		return;
	}

	nodeStr[strIndex++] = (char)root -> val + 48;

	if(NULL == root -> left && NULL == root -> right) {
		return;
	}

	nodeStr[strIndex++] ='(';
	treeToString(root -> left);
	nodeStr[strIndex++] = ')';

	nodeStr[strIndex++] ='(';
	treeToString(root -> right);
	nodeStr[strIndex++] = ')';
}


char * tree2str(struct TreeNode* root) {
	nodeStr = malloc(5000 * sizeof(char));
	strIndex = 0;

	treeToString(root);

	nodeStr[strIndex] = '\0';

	return nodeStr;
}

