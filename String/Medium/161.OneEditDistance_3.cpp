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
		int sSize = source.size();

		for (int i = 0; i < sSize; i++) {
			if (source[i] != destination[i]) {
				return source.substr(i) == destination.substr(i + 1);
			}
		}

		return true;
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

        int sSize = source.size();
        int tSize = target.size();

        if (absoulte(sSize - tSize) > 1) {
        	return false;
        }

        if (sSize == tSize) {
        	//cout << "both equal" << endl;
        	for (int i = 0; i < sSize; i++) {
        		if (target[i] != source[i]) {
        			return source.substr(i + 1) == target.substr(i + 1);
        		}
        	}

        } else if (sSize < tSize) {
        	//cout << "small source" << endl;
        	return isTypos(source, target);
        }

        //cout << "small target" << endl;
        return isTypos(target, source);
    }
};