

class Solution {
	int dpScore[1001][1001];
	int mulSize;

	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

	int findScore(vector<int>& nums, vector<int>& multipliers, int left, int right, int index) {
		if (mulSize == index) {
			return 0;
		}

		if (-91 != dpScore[index][left]) {
			return dpScore[index][left];
		}


		return dpScore[index][left] = maxValue (
			multipliers[index] * nums[left] + findScore(nums, multipliers, left + 1, right, index + 1),
			multipliers[index] * nums[right] + findScore(nums, multipliers, left, right - 1, index + 1)
		);
	}

public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		mulSize = multipliers.size();
		for (int i = 0; i <= mulSize; i++) {
			for (int j = 0; j <= mulSize; j++) {
				dpScore[i][j] = -91;
			}
		}


		return findScore(nums, multipliers, 0, nums.size() - 1, 0);
	}
};