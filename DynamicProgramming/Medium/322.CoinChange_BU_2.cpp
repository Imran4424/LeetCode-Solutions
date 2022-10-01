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

		sort(coins.begin(), coins.end());

		// cause amount 0 has no coins
		dp[0] = 0;

		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < coins.size(); ++j) {
				int current = i - coins[j];

				if (current >= 0) {
					dp[i] = minValue(dp[i], 1 + dp[current]);
				} else {
					break;
				}
			}

		}

		if (dp[amount] == amount + 1) {
			return -1;
		}

		return dp[amount];
	}
};