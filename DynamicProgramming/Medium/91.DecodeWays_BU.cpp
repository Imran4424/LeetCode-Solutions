
class Solution {

public:
	int numDecodings(string code) {
		// invalid ways
		if ('0' == code[0]) {
			return 0;
		}

		const int codeSize = code.size();

		// initialization
		int dp[codeSize + 1];
		for (int i = 0; i <= codeSize; ++i) {
			dp[i] = 0;
		}

		// empty set
		dp[0] = 1;
		// first character which is not zero, so it will must be one
		// forward consideration
		dp[1] = 1;

		// starting from second index of code
		for (int i = 1; code[i]; ++i) {
			// one digit
			if ('0' != code[i]) {
				dp[i + 1] += dp[i];
			}

			// two digit
			// here forward to backward
			// in this way no need to check 2 digit valid or not
			if ('1' == code[i - 1] || ('2' == code[i - 1] && code[i] <= '6')) {
				dp[i + 1] += dp[i - 1];
			}

		}

		return dp[codeSize];
	}
};