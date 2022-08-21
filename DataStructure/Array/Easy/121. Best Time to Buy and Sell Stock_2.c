/*
	One Pass
*/

int maxProfit(int* prices, int pricesSize) {
	int maxDiff = 0;
	int minSoFar = INT_MAX;

	for (int i = 0; i < pricesSize; i++) {
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
