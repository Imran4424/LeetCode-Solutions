/*
        In this solution we will use 

        bidirectional dynamic programming.
*/


class Solution {
int maxValue(int x, int y) {
        if (x > y) {
                return x;
        }

        return y;
}

public:
        int maxProfit(vector<int>& prices) {
                int length = prices.size();

                if (length < 2) {
                        return 0;
                }

                int leftMin = prices[0];
                int rightMax = prices[length - 1];

                int leftProfit[length], rightProfit[length + 1];
                // for escaping garbage value
                leftProfit[0] = 0;
                leftProfit[1] = 0;
                rightProfit[length] = 0;
                rightProfit[length - 1] = 0;

                for (int left = 1; left < prices.size(); ++left) {
                        leftProfit[left] = maxValue(leftProfit[left - 1], prices[left] - leftMin);

                        // min so far for left sequence
                        if (prices[left] < leftMin) {
                                leftMin = prices[left];
                        }

                        int right = length - left - 1;

                        rightProfit[right] = maxValue(rightProfit[right + 1], rightMax - prices[right]);
                        // max so far for right sequence
                        rightMax = maxValue(rightMax, prices[right]);
                }

                int maxProfit = 0;

                for (int i = 0; i < length; i++) {
                        maxProfit = maxValue(maxProfit, leftProfit[i] + rightProfit[i + 1]);
                }

                return maxProfit;
        }
};