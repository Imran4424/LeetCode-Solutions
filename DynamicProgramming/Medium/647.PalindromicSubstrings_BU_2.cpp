
class Solution {
	void checkPalindrome(string &text, int left, int right, int &palindromeCount) {

		while (left >= 0 && text[right] && text[left] == text[right]) {
			palindromeCount++;

			--left;
			++right;
		}
	}
    
public:
	int countSubstrings(string text) {
		int palindromeCount = 0;

		for (int i = 0; text[i]; ++i) {
			// odd
			checkPalindrome(text, i, i, palindromeCount);

			// even
			checkPalindrome(text, i, i + 1, palindromeCount);
		}

		return palindromeCount;
	}
};