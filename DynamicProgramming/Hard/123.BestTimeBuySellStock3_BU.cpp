class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        int localMax = prices[0];
        int localMin = prices[0];
        int k = 2;
        
        for (int i = 1; i < prices.size() && k; ++i) {
            if (prices[i] < localMax) {
                if (localMax - localMin > 0) {
                    k--;
                }

                total += localMax - localMin;
                localMax = prices[i];
                localMin = prices[i];
            } else {
                localMax = prices[i];
            }
        }
        
        total += localMax - localMin;
        
        return total;
    }
};