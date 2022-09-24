
class Solution {
    	const long long int modVal = 1000000007;
public:
	int numDecodings(string code) {
		// invalid ways
		if ('0' == code[0]) {
			return 0;
		}

		// empty set
		int secondPrev = 1;

		// first element
		int prev = 1;
		if ('*' == code[0]) {
			prev = 9;
		} else {
			prev = 1;
		}

		// start from second Index
		for (int i = 1; code[i]; ++i) {
			int current = 0;

			// one digit
			if('*' == code[i]) {
				current = (current + (9 * (prev % modVal)) % modVal) % modVal;
			} else if ('0' != code[i]) {
				current = (current + prev) % modVal;
			}

			// two digit
			// here forward to backward
			// in this way no need to check 2 digit valid or not

			if ('*' == code[i - 1]) {
				if ('*' == code[i]) {
					current = (current + (15 * (secondPrev % modVal)) % modVal) % modVal;
				} else if (code[i] <= '6') {
					current = (current + (2 * (secondPrev % modVal)) % modVal) % modVal;
				} else {
					current = (current + secondPrev) % modVal;
				}
			} else if ('1' == code[i - 1]) {
				if ('*' == code[i]) {
					current = (current + (9 * (secondPrev % modVal)) % modVal) % modVal;
				} else {
					current = (current + secondPrev) % modVal;
				}
			} else if ('2' == code[i - 1]) {
				if ('*' == code[i]) {
					current = (current + (6 * (secondPrev % modVal)) % modVal) % modVal;
				} else if (code[i] <= '6') {
					current = (current + secondPrev) % modVal;
				}
			}

			secondPrev = prev;
			prev = current;
		}

		return prev;
	}
};