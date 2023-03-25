
class Solution {
	int dp[2501][2501];
    
	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}
    
	int dpSequence(vector<int> &nums, int index, int inHand) {
		if (index >= nums.size()) {
			return 0;
		}

		// + 1 - incase of inhand -1 it won't crash
		if (dp[index][inHand + 1] != -1) {
			return dp[index][inHand + 1];
		}

		int notSkip = 0;
		int skip = dpSequence(nums, index + 1, inHand);


		if (-1 == inHand || nums[index] > nums[inHand]) {
			notSkip =  1 + dpSequence(nums, index + 1, index);
		}

		return dp[index][inHand + 1] = maxValue(skip, notSkip);
	}
	
public:
	int lengthOfLIS(vector<int>& nums) {
		int maxSeq = 0;
		for (int i = 0; i <= nums.size(); ++i) {
			for (int j = 0; j <= nums.size(); ++j) {
				dp[i][j] = -1;   
			}
		}

		return dpSequence(nums, 0, -1);
	}
};