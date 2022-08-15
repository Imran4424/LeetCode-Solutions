
class Solution {

	string textOne, textTwo;
	int leftSize, rightSize;
	int dp[1001][1001];

	int LCS(int i, int j) {
		if (leftSize == i || rightSize == j) {
			return 0;
		}

		if(-1 != dp[i][j]) {
			return dp[i][j];
		}

		if (textOne[i] == textTwo[j]) {
			return dp[i][j] = 1 + LCS(i + 1, j + 1);
		}

		int left = LCS(i + 1, j);
		int right = LCS(i, j + 1);

		if (left > right) {
			return dp[i][j] = left;
		}

		return dp[i][j] = right;
	}

public:
	int longestCommonSubsequence(string textOne, string textTwo) {
		this -> textOne = textOne;
		this -> textTwo = textTwo;
		leftSize = textOne.size();
		rightSize = textTwo.size();

		for (int i = 0; i <= leftSize; i++) {
			for (int j = 0; j <= rightSize; j++) {
				dp[i][j] = -1;
			}
		}

		return LCS(0, 0); 
	}
};