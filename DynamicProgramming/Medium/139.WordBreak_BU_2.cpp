

class Solution {
public:
	bool wordBreak(string text, vector<string>& wordDict) {
		bool dp[text.size() + 1];

		for (int i = 0; text[i]; ++i) {
			dp[i] = false;
		}

		// base case
		dp[text.size()] = true;


		int i = 0;
		for (i = text.size() - 1; i >= 0; --i) {
			for (string &word : wordDict) {
				// first condition to check, if it out of bound or not
				// when using substr() with c++ we can omit first condition
				// second condition to generate substring and compare it to dictory word
				if (i + word.size() <= text.size() && text.substr(i, word.size()) == word) {
					dp[i] = dp[i + word.size()];
				}

				if(dp[i]) {
					break;
				}
			}
		}

		return dp[0];
	}
};