
class Solution {

	int dp[1001][1001];

	int LCS(string textOne, string textTwo, int count) {
		int leftSize = textOne.size();
		int rightSize = textTwo.size();

		if (leftSize == 0 ||rightSize == 0) {
			return count;
		}

		if(0 != dp[leftSize][rightSize]) {
			return dp[leftSize][rightSize];
		}

		if (textOne[0] == textTwo[0]) {
			// here passing the count will cause multiple unccessary updates for dp array along the way
			// that way, dp array will not updated when it truly needed to update
			return dp[leftSize][rightSize] = LCS(textOne.substr(1), textTwo.substr(1), count + 1);
		}

		// here passing the count will cause multiple unccessary updates for dp array along the way
		// that way, dp array will not updated when it truly needed to update
		int left = LCS(textOne.substr(1), textTwo, count);
		int right = LCS(textOne, textTwo.substr(1), count);

		if (left > right) {
			return dp[leftSize][rightSize] = left;
		}

		return dp[leftSize][rightSize] = right;
	}

public:
	int longestCommonSubsequence(string textOne, string textTwo) {
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				dp[i][j] = 0;
			}
		}

		return LCS(textOne, textTwo, 0); 
	}
};

/*
	this code will give you wrong answser

	cause dp is updating along the call with unnecessary updates

	cause we are passing count along the call

*/