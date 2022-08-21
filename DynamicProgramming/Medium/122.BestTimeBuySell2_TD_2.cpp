class Solution {
	int dp[30001][2];

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

		int sellProf = 0;

		if (prices[index] > broughtPrice) {
			// sending the next index, no need to buy the same day
			sellProf = (prices[index] - broughtPrice) + findProfit(prices, index + 1, !buy, 0);
		}

		// skipping not buying
		int notSellProf = findProfit(prices, index + 1, buy, broughtPrice);

		if (sellProf > notSellProf) {
			return dp[index][buy] = sellProf;
		}
		
		return notSellProf;
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