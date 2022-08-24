class Solution {
        int maxValue(int x, int y) {
                if (x > y) {
                        return x;
                }

                return y;
        }

public:
        int maxProfit(vector<int>& prices) {
                int firstTransactionCost = prices[0];
                int firstTransactionProfit = 0;

                int mostMoneyInPocket = -prices[0];
                int profitFromTwoTransactions  = 0;

                for (int i = 0; i < prices.size(); ++i) {
                        firstTransactionCost = maxValue(firstTransactionCost, prices[i]);
                        firstTransactionProfit = maxValue(firstTransactionProfit, prices[i] - firstTransactionCost);

                        mostMoneyInPocket  = maxValue(mostMoneyInPocket , firstTransactionProfit - prices[i]);
                        profitFromTwoTransactions = maxValue(profitFromTwoTransactions, mostMoneyInPocket + prices[i]);
                }

                return profitFromTwoTransactions;
        }
};