/*
	One Pass
*/

int maxProfit(int* prices, int pricesSize) {
	int firstMinBeforeMax = -1;
	int i;
	for(i = 0; i < pricesSize - 1; i++) {
		if(prices[i] < prices[i + 1]) {
			firstMinBeforeMax = prices[i];
			break;
		}
	}

	if(-1 == firstMinBeforeMax) {
		return 0;
	}

	int maxAfterMin = firstMinBeforeMax;

	for(; i < pricesSize; i++) {
		if(prices[i] > maxAfterMin) {
			maxAfterMin = prices[i];
		}
	}

	return maxAfterMin - firstMinBeforeMax;
}
