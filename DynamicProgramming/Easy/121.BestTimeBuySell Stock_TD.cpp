class Solution {
	int dp[100001][2];

	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

	int findProfit(vector <int>& prices, int index, bool buy) {
		if (index >= prices.size()) {
			return 0;
		}

		if (-1 != dp[index][buy]) {
			return dp[index][buy];
		}

		if (buy) {
			// buying and setting brought price to current price
			int buyProf = findProfit(prices, index + 1, !buy);

			// skipping not buying
			int notBuyProf = findProfit(prices, index + 1, buy);

			return dp[index][buy] = maxValue(buyProf - prices[index], notBuyProf);
		} 

		// just selling, no forward call, single transaction
		int sellProf = prices[index];

		// skipping not buying
		int notSellProf = findProfit(prices, index + 1, buy);

		return dp[index][buy] = maxValue(sellProf, notSellProf);
	}

public:
	int maxProfit(vector<int>& prices) {
		for (int i = 0; i <= prices.size(); ++i) {
			dp[i][0] = dp[i][1] = -1;
		}

		return findProfit(prices, 0, true);
	}
};