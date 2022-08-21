class Solution {
	int dp[1001][2][101];

	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

	int findProfit(vector <int>& prices, int index, bool buy, int transaction) {
		if (index >= prices.size() || 0 == transaction) {
			return 0;
		}

		if (-1 != dp[index][buy][transaction]) {
			return dp[index][buy][transaction];
		}

		if (buy) {
			// buying and setting brought price to current price
			int buyProf = findProfit(prices, index + 1, !buy, transaction);

			// skipping not buying
			int notBuyProf = findProfit(prices, index + 1, buy, transaction);

			return dp[index][buy][transaction] = maxValue(buyProf - prices[index], notBuyProf);
		} 

		// sending the next index, no need to buy the same day
		int sellProf = prices[index] + findProfit(prices, index + 1, !buy, transaction - 1);

		// skipping not buying
		int notSellProf = findProfit(prices, index + 1, buy, transaction);
		
		return dp[index][buy][transaction] = maxValue(sellProf, notSellProf);
	}

public:
	int maxProfit(int transaction, vector<int>& prices) {
		// 3D vector for 3 states
		// price, buy/sell, transaction
		for (int i = 0; i <= prices.size(); ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k <= transaction; ++k) {
					dp[i][j][k] = -1;
				}
			}
		}

		return findProfit(prices, 0, true, transaction);
	}
};
