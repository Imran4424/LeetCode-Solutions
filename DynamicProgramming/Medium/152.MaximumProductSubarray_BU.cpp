


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

		if (nums.size() == 1) {
			return nums[0];
		}

		int dp[nums.size()][2];
		dp[0][0] = nums[0];
		dp[0][1] = nums[0];
        
        	int maxP = nums[0];
		
		for (int i = 1; i < nums.size(); ++i) {
			vector <int> current;
			current.push_back(nums[i]);
			current.push_back(dp[i - 1][0] * nums[i]);
			current.push_back(dp[i - 1][1] * nums[i]);
            
			sort(current.begin(), current.end());
            
			// 0 - min
			// 1 - max
			dp[i][0] = current[0];
			dp[i][1] = current[current.size() - 1];
            
			if (dp[i][1] > maxP) {
				maxP = dp[i][1];
			}
		}

		return maxP;
	}
};

