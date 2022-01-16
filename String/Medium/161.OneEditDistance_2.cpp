/*
	Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

	A string s is said to be one distance apart from a string t if you can:

	Insert exactly one character into s to get t.
	Delete exactly one character from s to get t.
	Replace exactly one character of s with a different character to get t.
	 

	Example 1:

	Input: s = "ab", t = "acb"
	Output: true
	Explanation: We can insert 'c' into s to get t.
	Example 2:

	Input: s = "", t = ""
	Output: false
	Explanation: We cannot get t from s by only one step.
	Example 3:

	Input: s = "a", t = ""
	Output: true
	Example 4:

	Input: s = "", t = "A"
	Output: true
	 

	Constraints:

	0 <= s.length <= 104
	0 <= t.length <= 104
	s and t consist of lower-case letters, upper-case letters and/or digits.

*/

class Solution {
	char specialChar = '*';

	bool isTypos(string source, string destination) {
		for (int i = 0; i < destination.size(); i++) {
			string reserve = source;
			char res = destination[i];

			source.insert(i, string(1, specialChar));
			destination[i] = specialChar;

			if (source == destination) {
				return true;
			}

			source = reserve;
			destination[i] = res;
		}

		return false;
	}

	int absoulte(int x) {
		if (x < 0) {
			return -x;
		}

		return x;
	}

public:
    bool isOneEditDistance(string source, string target) {
        if (source == target) {
        	return false;
        }

        if (absoulte(source.size() - target.size()) > 1) {
        	return false;
        }

        if (source.size() == target.size()) {
        	//cout << "both equal" << endl;
        	for (int i = 0; source[i]; i++) {
        		char res = source[i];
        		char tarRes = target[i];

        		source[i] = target[i] = specialChar;

        		if (source == target) {
        			return true;
        		}

        		source[i] = res;
        		target[i] = tarRes;
        	}

        	return false;
        } else if (source.size() < target.size()) {
        	//cout << "small source" << endl;
        	return isTypos(source, target);
        }

        //cout << "small target" << endl;
        return isTypos(target, source);
    }
};