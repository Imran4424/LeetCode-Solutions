
class Solution {

public:
	int numDecodings(string code) {
		// invalid ways
		if ('0' == code[0]) {
			return 0;
		}

		// empty set
		int secondPrev = 1;
		// first character which is not zero, so it will must be one
		// forward consideration
		int prev = 1;

		// starting from second index of code
		for (int i = 1; code[i]; ++i) {
			int current = 0;

			// one digit
			if ('0' != code[i]) {
				current += prev;
			}

			// two digit
			// here forward to backward
			// in this way no need to check 2 digit valid or not
			if ('1' == code[i - 1] || ('2' == code[i - 1] && code[i] <= '6')) {
				current += secondPrev;
			}


			secondPrev = prev;
			prev = current;
		}

		return prev;
	}
};