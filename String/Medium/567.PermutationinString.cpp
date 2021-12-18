/*
	Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

	In other words, return true if one of s1's permutations is the substring of s2.

	 

	Example 1:

	Input: s1 = "ab", s2 = "eidbaooo"
	Output: true
	Explanation: s2 contains one permutation of s1 ("ba").

	Example 2:

	Input: s1 = "ab", s2 = "eidboaoo"
	Output: false

	Constraints:

	    1 <= s1.length, s2.length <= 104
	    s1 and s2 consist of lowercase English letters.

*/

class Solution {
	vector<string> permutatedStrings;
	int *visited;

	void initVisited(int size) {
		visited = new int[size];

		for (int i = 0; i < size; i++) {
			visited[i] = 0;
		}
	}

	void permutation(string str, int index, string perStr) {
		if (index == str.size()) {
			permutatedStrings.push_back(perStr);
			reverse(perStr.begin(), perStr.end());
			permutatedStrings.push_back(perStr);
			return;
		}

		for (int i = 0; i < str.size(); i++) {
			if(!visited[i]) {
				perStr.push_back(str[i]);
				visited[i] = 1;

				permutation(str, index + 1, perStr);

				perStr.pop_back(); // backtracking
				visited[i] = 0; // backtracking
			}
		}
	}
public:
    bool checkInclusion(string s1, string s2) {
        permutatedStrings = vector <string>();
        initVisited(s1.size());
        permutation(s1, 0, "");

        for (string perWord : permutatedStrings) {
        	if (s2.find(perWord) != string::npos) {
        		return true;
        	}
        }

        return false;
    }
};

/*
	This code ended up in TLE
*/