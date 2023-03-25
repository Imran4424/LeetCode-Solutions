


class Solution {
	int dp[2501] = { 0 };
    
	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}
    
	int dpSequence(vector<int> nums, int index, int inHand) {
		if (index >= nums.size()) {
			return 1;
		}

		if (dp[index] != 0) {
			return dp[index];
		}

		if (nums[index] > inHand) {
			int skip = dpSequence(nums, index + 1, inHand);
			int notSkip =  1 + dpSequence(nums, index + 1, nums[index]);

			if (skip > notSkip) {
				return dp[index] = skip;
			}

			return dp[index] = notSkip;
		}

		return dp[index] = dpSequence(nums, index + 1, inHand);
	}
    
    
public:
int lengthOfLIS(vector<int>& nums) {
	int maxSeq = 0;

	for (int i = nums.size() - 1; i >= 0; --i) {
		maxSeq = maxValue(maxSeq, dpSequence(nums, i - 1, nums[i]));
	}

		return maxSeq;
	}
};