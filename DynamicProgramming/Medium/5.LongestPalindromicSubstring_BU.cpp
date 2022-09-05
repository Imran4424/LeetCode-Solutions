
class Solution {
	void checkPalindrome(string &text, int left , int right, int &maxLen, string &maxPalindrome) {
        
		while (left >= 0 && right < text.size() && text[left] == text[right]) {
			left--;
			right++;
		}
        
		// restore left, right
		left++;
		right--;
        
		if (right - left + 1 > maxLen) {
			maxLen = right - left + 1;

			maxPalindrome = "";

			for (int i = left; i <= right; ++i) {
				maxPalindrome.push_back(text[i]);
			}
		}
    	}
    
public:
	string longestPalindrome(string text) {
		int maxLen = 0;
		string maxPalindrome = "";

		int left, right;

		for (int i = 0; text[i]; ++i) {
			// odd lenth 
			checkPalindrome(text, i, i, maxLen, maxPalindrome);

			// even length
			checkPalindrome(text, i, i + 1, maxLen, maxPalindrome);
		}

		return maxPalindrome;
	}
};