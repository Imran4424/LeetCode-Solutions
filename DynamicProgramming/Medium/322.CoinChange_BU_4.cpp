class Solution {
	int minValue(int x, int y) {
		if (x < y) {
		    return x;
		}

		return y;
	}

public:
	int coinChange(vector<int>& coins, int amount) {
		vector <int> dp(amount + 1, amount + 1);

		// cause amount 0 has no coins
		dp[0] = 0;

		for (int &coin : coins) {
			for (int i = coin; i <= amount; ++i) {
				dp[i] = minValue(dp[i], 1 + dp[i - coin]);
			}

		}

		if (dp[amount] == amount + 1) {
			return -1;
		}

		return dp[amount];
	}
};