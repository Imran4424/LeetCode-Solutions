

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxDiff = 0;
		int minSoFar = INT_MAX;

		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < minSoFar) {
				minSoFar = prices[i];
			} else {
				int currentDiff = prices[i] - minSoFar;
				if (currentDiff > maxDiff) {
					maxDiff = currentDiff;
				}
			}
		}

		return maxDiff;
	}
};

/*
	one pass

	it's also DP
	unusual DP

*/