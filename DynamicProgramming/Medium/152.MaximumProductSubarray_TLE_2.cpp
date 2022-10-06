
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

		if (nums.size() == 1) {
			return nums[0];
		}


		int dp[nums.size()];
		dp[0] = nums[0];
		vector <int> negProduct;


		// reducing all continueous positive to one number
		if (dp[0] < 0) {
			negProduct.push_back(dp[0]);
		}

		for (int i = 1; i < nums.size(); ++i) {
			// initialization
			dp[i] = nums[i];

			if(dp[i] <= 0) {
				if (dp[i - 1] > 0) {
					negProduct.push_back(dp[i - 1]);
				}

				negProduct.push_back(dp[i]);
				continue;
			}

			int current = dp[i] * dp[i - 1];

			if (current > dp[i]) {
				dp[i] = current;
			}
		}

		if (dp[nums.size() - 1] > 0) {
			negProduct.push_back(dp[nums.size() - 1]);
		}
		

		int maxP = INT_MIN;
		// all substring
		for (int i = 0; i < negProduct.size(); ++i) {
			int current = 1;
			
			for (int j = i; j < negProduct.size(); ++j) {
				current *= negProduct[j];
				if (current > maxP) {
					maxP = current;
				}
			}
		}
		

		return maxP;
	}
};

/*
	Improvement on previous one


	This code will end up in TLE
	Complexity O(n^2)

	all substring logic

*/