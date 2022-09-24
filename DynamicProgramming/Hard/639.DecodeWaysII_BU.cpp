
class Solution {
    	const long long int modVal = 1000000007;

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
		int left = 0;
	        if ('*' == code[index]) {
	        	left =  (9 * (dpDecoding(code, index + 1) % modVal)) % modVal;
	        } else {
	        	left = dpDecoding(code, index + 1) % modVal;
	        }

		// this is 2 digit extra count correction
		// checking 2 digit call valid or not
		if (index + 2 > code.size()) {
			return dp[index] = left;
		}
        
        	int right = 0;

		// 2 digit
		if ('*' == code[index]) {
			if ('*' == code[index + 1]) {
				right = (15 * (dpDecoding(code, index + 2) % modVal)) % modVal;
			} else if (code[index + 1] <= '6') {
				right = (2 * (dpDecoding(code, index + 2) % modVal)) % modVal;
			} else {
				right = dpDecoding(code, index + 2) % modVal;
			}
		} else if ('1' == code[index]) {
			if ('*' == code[index + 1]) {
				right = (9 * (dpDecoding(code, index + 2) % modVal)) % modVal;
			} else {
				right = dpDecoding(code, index + 2) % modVal;
			}
		} else if ('2' == code[index]){
			if ('*' == code[index + 1]) {
				right = (6 * (dpDecoding(code, index + 2) % modVal)) % modVal;
			} else if (code[index + 1] <= '6') {
				right = dpDecoding(code, index + 2) % modVal;
			}
		}
	
		// addition, add modal
		return dp[index] = (left + right) % modVal;
	}

public:
	int numDecodings(string code) {
		// invalid ways
		if ('0' == code[0]) {
			return 0;
		}

		const int codeSize = code.size();
		int dp[codeSize + 1];

		// empty set
		dp[0] = 0;

		// first element
		if ('*' == code[0]) {
			dp[1] = 9;
		} else {
			dp[1] = 1;
		}



		return dp[codeSize];
	}
};