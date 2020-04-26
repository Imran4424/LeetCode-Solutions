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

int Absolute(int x) {
	if(x < 0) {
		return -x;
	}

	return x;
}

void treeToString(struct TreeNode* root) {
	if(NULL == root) {
		return;
	}

	if(root -> val < 0) {
		nodeStr[strIndex++] = '-';
	}

	nodeStr[strIndex++] = (char) Absolute(root -> val) + 48;

	if(NULL == root -> left && NULL == root -> right) {
		return;
	}

	nodeStr[strIndex++] ='(';
	treeToString(root -> left);
	nodeStr[strIndex++] = ')';

	if(NULL == root -> right) {
		return;
	}

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

