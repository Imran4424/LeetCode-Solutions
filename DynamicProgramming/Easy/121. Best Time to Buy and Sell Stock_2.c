/*
	One Pass
*/

int maxProfit(int* prices, int pricesSize) {
	int firstMinBeforeMax = 0;
	int i;
	for(i = 0; i < pricesSize - 1; i++) {
		if(prices[i] < prices[i + 1]) {
			firstMinBeforeMax = prices[i];
			break;
		}
	}

	for(; i < pricesSize; i++) {
		
	}
}
