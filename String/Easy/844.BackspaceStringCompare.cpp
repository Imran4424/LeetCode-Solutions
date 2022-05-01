/*

	Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
	'#' means a backspace character.

	Note that after backspacing an empty text, the text will continue empty.


	Example 1:

	Input: s = "ab#c", t = "ad#c"
	Output: true
	Explanation: Both s and t become "ac".

	Example 2:

	Input: s = "ab##", t = "c#d#"
	Output: true
	Explanation: Both s and t become "".

	Example 3:

	Input: s = "a#c", t = "b"
	Output: false
	Explanation: s becomes "c" while t becomes "b".


	Constraints:

    	1 <= s.length, t.length <= 200
    	s and t only contain lowercase letters and '#' characters.
*/


class Solution {
	string performBackspace(string text) {
		int i = 0;
		while (text[i]) {
			if ('#' == text[i]) {
				if (i - 1 >= 0) {
					i--;
					text.erase(i, 2);
				} else {
					text.erase(i , 1);
				}
			} else {
				i++;
			}
		}

		return text;
	}

public:
	bool backspaceCompare(string s, string t) {
		return performBackspace(s) == performBackspace(t);
	}
};
