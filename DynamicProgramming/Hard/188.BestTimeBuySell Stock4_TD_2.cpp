class Solution {
	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

	int findProfit(vector <int>& prices, int index, bool buy, int broughtPrice, int transaction) {
		if (index >= prices.size() || 0 == transaction) {
			return 0;
		}

		if (buy) {
			// buying and setting brought price to current price
			int buyProf = findProfit(prices, index + 1, !buy, prices[index], transaction);

			// skipping not buying
			int notBuyProf = findProfit(prices, index + 1, buy, 0, transaction);

			return maxValue(buyProf, notBuyProf);
		} 

		int sellProf = 0;

		if (prices[index] > broughtPrice) {
			// sending the next index, no need to buy the same day
			sellProf = (prices[index] - broughtPrice) + findProfit(prices, index + 1, !buy, 0, transaction - 1);
		}

		// skipping not buying
		int notSellProf = findProfit(prices, index + 1, buy, broughtPrice, transaction);
		
		return maxValue(sellProf, notSellProf);
	}

public:
	int maxProfit(int k, vector<int>& prices) {
		return findProfit(prices, 0, true, 0, k);
	}
};

/*
	This approach succeeds in recursion

	but fails in memorization

	duplicate update issue

	Without memorization TLE at 210
*/