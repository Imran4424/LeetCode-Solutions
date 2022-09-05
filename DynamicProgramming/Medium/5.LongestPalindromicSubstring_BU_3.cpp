

class Solution {
	void checkPalindrome(string &text, int left , int right, int &maxStart, int &maxLen) {

		while (left >= 0 && right < text.size() && text[left] == text[right]) {
			left--;
			right++;
		}

		// cause both are incremented by 1
	        // left in left direction
	        // right in right direction
	        if (right - left - 1 > maxLen) {
			maxStart = left + 1;
			maxLen = right - left  - 1;
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

		// returning the substring 
	        // first parameter - start index
	        // second parameter - size
		return text.substr(maxStart, maxLen);
	}
};

/*
	for odd palindrome

	start at middle 

	left and right at same position at the beginning

	then add letters left and right

		a -> bab -> ababa

	for even palindrome

	start at middle 

	now, if left = i, then right = i + 1

		aa -> baab -> cbaabc -> acbaabca
*/