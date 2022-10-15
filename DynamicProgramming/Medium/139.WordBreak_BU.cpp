

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
				if (text.substr(i, word.size()) == word) {
					cout << text.substr(i, word.size()) << endl;
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