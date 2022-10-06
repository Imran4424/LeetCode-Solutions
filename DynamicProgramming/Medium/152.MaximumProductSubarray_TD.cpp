
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

		for (int i = 1; i < nums.size(); ++i) {
			vector <int> current;
			current.push_back(nums[i]);
			current.push_back(nums[i] * dp[i - 1][0]);
			current.push_back(nums[i] * dp[i - 1][1]);

		}
		

		return maxP;
	}
};

