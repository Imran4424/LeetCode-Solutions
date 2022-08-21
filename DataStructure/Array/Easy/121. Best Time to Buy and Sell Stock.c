

int maxProfit(int* prices, int pricesSize){
    int maxEarnProfit = 0;

    for(int i = 0; i < pricesSize; i++) {
        for(int j = i + 1;  j < pricesSize; j++) {
            if(prices[j] - prices[i] > maxEarnProfit) {
                maxEarnProfit = prices[j] - prices[i];
            }
        }
    }

    return maxEarnProfit;
}

