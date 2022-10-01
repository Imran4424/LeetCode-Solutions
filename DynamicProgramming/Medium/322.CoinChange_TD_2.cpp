
class Solution {

	const int myMax = 100001;	
	//int dp[10001];

	int dpCoinChange(vector<int>& coins, int amount, vector <int>& dp) {
		if (amount < 0) {
			return -1;
		}

		if (0 == amount) {
			return 0;
		}

		if (0 != dp[amount - 1]) {
			return dp[amount - 1];
		}

		int minCount = INT_MAX;

		for (int &coin : coins) {
			int currentCount = dpCoinChange(coins, amount - coin, dp);

			if (currentCount >= 0 && currentCount < minCount) {
				minCount = 1 + currentCount;
			}
		}

		if (minCount == INT_MAX) {
			return -1;
		}

		return dp[amount - 1] = minCount;
	}

public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount < 0) {
			return 0;
		}

		//sort(coins.begin(), coins.end());

		//vector <int> dp(amount, 0);

		return  dpCoinChange(coins, amount, vector<int>(amount, 0));
	}
};