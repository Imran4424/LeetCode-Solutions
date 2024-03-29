
class Solution {
    	const long long int modVal = 1000000007;
public:
	int numDecodings(string code) {
		// invalid ways
		if ('0' == code[0]) {
			return 0;
		}

		const int codeSize = code.size();
		int dp[codeSize + 1];
		for (int i = 0; i <= codeSize; ++i) {
			dp[i] = 0;
		}

		// empty set
		dp[0] = 1;

		// first element
		if ('*' == code[0]) {
			dp[1] = 9;
		} else {
			dp[1] = 1;
		}

		// start from second Index
		for (int i = 1; code[i]; ++i) {
			// one digit
			if('*' == code[i]) {
				dp[i + 1] = (dp[i + 1] + (9 * (dp[i] % modVal)) % modVal) % modVal;
			} else if ('0' != code[i]) {
				dp[i + 1] = (dp[i + 1] + dp[i]) % modVal;
			}

			// two digit
			// here forward to backward
			// in this way no need to check 2 digit valid or not

			if ('*' == code[i - 1]) {
				if ('*' == code[i]) {
					dp[i + 1] = (dp[i + 1] + (15 * (dp[i - 1] % modVal)) % modVal) % modVal;
				} else if (code[i] <= '6') {
					dp[i + 1] = (dp[i + 1] + (2 * (dp[i - 1] % modVal)) % modVal) % modVal;
				} else {
					dp[i + 1] = (dp[i + 1] + dp[i - 1]) % modVal;
				}
			} else if ('1' == code[i - 1]) {
				if ('*' == code[i]) {
					dp[i + 1] = (dp[i + 1] + (9 * (dp[i - 1] % modVal)) % modVal) % modVal;
				} else {
					dp[i + 1] = (dp[i + 1] + dp[i - 1]) % modVal;
				}
			} else if ('2' == code[i - 1]) {
				if ('*' == code[i]) {
					dp[i + 1] = (dp[i + 1] + (6 * (dp[i - 1] % modVal)) % modVal) % modVal;
				} else if (code[i] <= '6') {
					dp[i + 1] = (dp[i + 1] + dp[i - 1]) % modVal;
				}
			}
		}

		return dp[codeSize];
	}
};