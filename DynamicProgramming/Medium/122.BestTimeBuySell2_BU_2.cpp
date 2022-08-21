class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        int localMax = prices[0];
        int localMin = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < localMax) {
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