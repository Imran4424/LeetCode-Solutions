
class Solution {
	int checkPalindrome(string &text, int left, int right) {
		int palindromeCount = 0;

		while (left >= 0 && text[right] && text[left] == text[right]) {
			palindromeCount++;

			--left;
			++right;
		}

		return palindromeCount;
	}
    
public:
	int countSubstrings(string text) {
		int palindromeCount = 0;

		for (int i = 0; text[i]; ++i) {
			// odd
			palindromeCount += checkPalindrome(text, i, i);

			// even
			palindromeCount += checkPalindrome(text, i, i + 1);
		}

		return palindromeCount;
	}
};