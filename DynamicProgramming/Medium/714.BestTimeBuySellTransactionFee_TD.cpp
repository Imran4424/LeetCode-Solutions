class Solution {
	int dp[50001][2];
	int fee;

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

			// deducting fee from each transaction
			return dp[index][buy] = maxValue(buyProf - prices[index] - fee, notBuyProf);
		} 

		// sending the next index, no need to buy the same day
		int sellProf = prices[index] + findProfit(prices, index + 1, !buy);

		// skipping not buying
		int notSellProf = findProfit(prices, index + 1, buy);

		return dp[index][buy] = maxValue(sellProf, notSellProf);
	}

public:
	int maxProfit(vector<int>& prices, int fee) {
		this -> fee = fee;

		for (int i = 0; i <= prices.size(); ++i) {
			dp[i][0] = dp[i][1] = -1;
		}

		return findProfit(prices, 0, true);
	}
};
