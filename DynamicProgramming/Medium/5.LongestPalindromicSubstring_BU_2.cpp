
class Solution {
	void checkPalindrome(string &text, int left , int right, int &maxStart, int &maxLen) {

		while (left >= 0 && right < text.size() && text[left] == text[right]) {
			left--;
			right++;
		}

		// restore left, right
		left++;
		right--;

		if (right - left + 1 > maxLen) {
			maxStart = left;
			maxLen = right- left  + 1;
		}
	}
    
public:
	string longestPalindrome(string text) {
		int maxStart = 0;
		int maxLen = 0;

		int left, right;

		for (int i = 0; text[i]; ++i) {
			// odd lenth 
			checkPalindrome(text, i, i, maxStart, maxLen);

			// even length
			checkPalindrome(text, i, i + 1, maxStart, maxLen);
		}

		return text.substr(maxStart, maxLen);
	}
};