

class Solution {
	int maxVal(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

public:
	int lengthOfLIS(vector<int>& nums) {
		int dp[nums.size()];
		
		for (int i = 0; i < nums.size(); ++i) {
			dp[i] = 1;
		}

		for (int i = nums.size() - 1; i >= 0; --i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] < nums[j]) {
					dp[i] = maxVal(dp[i], 1 + dp[j]);
				}
			}
		}

		int maxVal = dp[0];

		for (int i = 1; i < nums.size(); ++i) {
			if (dp[i] > maxVal) {
				maxVal = dp[i];
			}
		}

		return maxVal;
	}
};