
/*
	Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

	A shift on s consists of moving the leftmost character of s to the rightmost position.

	    For example, if s = "abcde", then it will be "bcdea" after one shift.

	 

	Example 1:

	Input: s = "abcde", goal = "cdeab"
	Output: true

	Example 2:

	Input: s = "abcde", goal = "abced"
	Output: false

	 

	Constraints:

	    1 <= s.length, goal.length <= 100
	    s and goal consist of lowercase English letters.

*/

class Solution {
	string rotate(string str) {
		char ch = str[0];
		str = str.substr(1);
		str.push_back(ch);

		return str;
	}

public:
	bool rotateString(string s, string goal) {
		if (s == goal) {
			return true;
		}

        	for (int i = 0; i < s.size() - 1; i++) {
        		s = rotate(s);

        		if (s == goal) {
        			return true;
        		}
        	}

        	return false;
	}
};