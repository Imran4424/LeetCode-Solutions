
class Solution {

	int dp[101];

	int dpDecoding(string &code, int index) {
		if (index == code.size()) {
			return 1;
		}

		if ('0' == code[index]) {
			return 0;
		}

		if (-1 != dp[index]) {
			return dp[index];
		}

		// 1 digit
		int left = dpDecoding(code, index + 1);
		int right = 0;

		// this is 2 digit extra count correction
		// checking 2 digit call valid or not
		if (index + 2 > code.size()) {
			return dp[index] = left;
		}

		// 2 digit
		// here
		// backward to forward
		if ('1' == code[index] || ('2' == code[index] && code[index + 1] <= '6')) {
			right = dpDecoding(code, index + 2);
		}
	
		return dp[index] = left + right;
	}

public:
	int numDecodings(string code) {
		// invalid ways
		if ('0' == code[0]) {
			return 0;
		}

		for (int i = 0; code[i]; ++i) {
			dp[i] = -1;
		}

		return dpDecoding(code, 0);
	}
};