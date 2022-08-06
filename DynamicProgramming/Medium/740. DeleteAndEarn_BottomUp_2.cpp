


class Solution {
	unordered_map <int, int> points;

	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

public:
	int deleteAndEarn(vector<int>& nums) {
		int maxNumber = 0;

		for (int i = 0; i < nums.size(); i++) {
			points[nums[i]] = points[nums[i]] + nums[i];

			maxNumber = maxValue(maxNumber, nums[i]);
		}

		int dpEarn[maxNumber + 1];

		dpEarn[0] = 0;
		dpEarn[1] = points[1];

		for (int i = 2; i <= maxNumber; i++) {
			dpEarn[i] = maxValue(dpEarn[i - 1], dpEarn[i - 2] + points[i]);
		}

		return dpEarn[maxNumber];
	}	
};