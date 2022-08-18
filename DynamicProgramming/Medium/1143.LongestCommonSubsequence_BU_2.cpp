
class Solution {
	int maxVal(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

public:
	int longestCommonSubsequence(string textOne, string textTwo) {
		int dp[textOne.size() + 1][textTwo.size() + 1];

		for (int i = 0; i <= textOne.size(); i++) {
			for (int j = 0; j <= textTwo.size(); j++) {
				dp[i][j] = 0;
			}
		}

		for (int i = textOne.size() - 1; i >= 0; i--) {
			for (int j = textTwo.size() - 1; j >= 0; j--) {
				if (textOne[i] == textTwo[j]) {
					dp[i][j] = 1 + dp[i + 1][j + 1];
				} else {
					dp[i][j] = maxVal(dp[i + 1][j], dp[i][j + 1]);
				}
			}
		}


		return dp[0][0];
	}
};