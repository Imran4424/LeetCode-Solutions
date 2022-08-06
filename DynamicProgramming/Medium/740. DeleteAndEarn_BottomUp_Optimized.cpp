


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


		int twoBack = 0;
		int oneBack = points[1];
		int maxEarn = oneBack;

		for (int i = 2; i <= maxNumber; i++) {
			maxEarn = maxValue(oneBack, twoBack + points[i]);
			twoBack = oneBack;
			oneBack = maxEarn;
		}

		return maxEarn;
	}	
};