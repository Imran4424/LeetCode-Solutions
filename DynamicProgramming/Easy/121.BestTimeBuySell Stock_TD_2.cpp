class Solution {
	int dp[300001][2];

	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

	int findProfit(vector <int>& prices, int index, bool buy, int broughtPrice) {
		if (index >= prices.size()) {
			return 0;
		}

		if (-1 != dp[index][buy]) {
			return dp[index][buy];
		}

		if (buy) {
			// buying and setting brought price to current price
			int buyProf = findProfit(prices, index + 1, !buy, prices[index]);

			// skipping not buying
			int notBuyProf = findProfit(prices, index + 1, buy, 0);

			return dp[index][buy] = maxValue(buyProf, notBuyProf);
		} 

		// just selling, no forward call, single transaction
		int sellProf = 0;

		if (prices[index] > broughtPrice) {
			sellProf = prices[index] - broughtPrice;
		}

		// skipping not buying
		int notSellProf = findProfit(prices, index + 1, buy, broughtPrice);

		return dp[index][buy] = maxValue(sellProf, notSellProf);
	}

public:
	int maxProfit(vector<int>& prices) {
		for (int i = 0; i <= prices.size(); ++i) {
			dp[i][0] = dp[i][1] = -1;
		}

		return findProfit(prices, 0, true, 0);
	}
};

/*
	This approach succeeds in recursion

	but fails in memorization

	duplicate update issue
*/