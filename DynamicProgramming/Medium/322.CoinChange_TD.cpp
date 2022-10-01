
class Solution {

	const int myMax = 100001;	
	int dp[10001];

	int dpCoinChange(vector<int>& coins, int amount) {
		if (amount < 0) {
			return -1;
		}

		if (0 == amount) {
			return 0;
		}

		if (myMax != dp[amount]) {
			return dp[amount];
		}

		int minCount = INT_MAX;

		for (int &coin : coins) {
			int currentCount = dpCoinChange(coins, amount - coin);

			if (-1 == currentCount) {
				continue;
			}

			minCount = min(minCount, 1 + currentCount);
		}

		if (minCount == INT_MAX) {
			return -1;
		}

		return dp[amount] = minCount;
	}

public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount < 1) {
			return 0;
		}

		for (int i = 0; i <= amount; ++i) {
			dp[i] = myMax;
		}

		return  dpCoinChange(coins, amount);
	}
};

/*
	Coin Change
	
	Getting TLE
*/