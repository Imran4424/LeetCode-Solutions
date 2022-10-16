


class Solution {
public:
	bool wordBreak(string text, vector<string>& wordDict) {
		// dumb value
		//text = " " + text;
		int size = text.size();
		bool dp[size + 1];

		for (int i = 0; i <= size; ++i) {
			dp[i] = false;
		}

		// making base case
		dp[0] = true;
		for (int i = 1; i <= size; ++i) {
			for (int k = 0; k < i; ++k) {
				for (string &word : wordDict) {
					if (text.substr(k, i - k) == word) {
						dp[i] = dp[i - word.size()];
					}

					if (dp[i]) {
						break;
					}
				}
			}			
		}

		return dp[size];
	}
};


/*
	O(n^3)
*/