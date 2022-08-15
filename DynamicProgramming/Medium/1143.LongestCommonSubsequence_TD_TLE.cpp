
class Solution {

	int dp[1001][1001];

	int LCS(string textOne, string textTwo) {
		int leftSize = textOne.size();
		int rightSize = textTwo.size();

		if (leftSize == 0 ||rightSize == 0) {
			return 0;
		}

		if(-1 != dp[leftSize][rightSize]) {
			return dp[leftSize][rightSize];
		}

		if (textOne[0] == textTwo[0]) {
			return dp[leftSize][rightSize] = 1 + LCS(textOne.substr(1), textTwo.substr(1));
		}

		int left = LCS(textOne.substr(1), textTwo);
		int right = LCS(textOne, textTwo.substr(1));

		if (left > right) {
			return dp[leftSize][rightSize] = left;
		}

		return dp[leftSize][rightSize] = right;
	}

public:
	int longestCommonSubsequence(string textOne, string textTwo) {
		for (int i = 0; i <= textOne.size(); i++) {
			for (int j = 0; j <= textTwo.size(); j++) {
				dp[i][j] = -1;
			}
		}

		return LCS(textOne, textTwo); 
	}
};