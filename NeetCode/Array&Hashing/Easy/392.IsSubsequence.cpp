class Solution {
public:
	bool isSubsequence(string s, string t) {
		int k = 0;

		for (int i = 0; t[i]; ++i) {
			if(s[k] == t[i]) {
				k++;
			}
		}

		if (s.size() == k) {
			return true;
		}

		return false;
	}
};