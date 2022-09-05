
class Solution {
	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

	int dpRob(vector<int>& nums, int index, int size) {
		int robOne = 0;
		int robTwo = 0;

		for (int i = index; i < size; i++) {
			int currentRob = maxValue(robTwo, robOne + nums[i]);
			robOne = robTwo;
			robTwo = currentRob;
		}

		return robTwo;
	}
    
public:
	int rob(vector<int>& nums) {
		if (nums.size() < 2) {
		    return nums[0];
		}

		return maxValue(dpRob(nums, 0, nums.size() - 1), dpRob(nums, 1, nums.size()));
	}
};