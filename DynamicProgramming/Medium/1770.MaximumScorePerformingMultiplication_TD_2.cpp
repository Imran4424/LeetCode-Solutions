

class Solution {
	int dpScore[1001][1001];
	int mulSize;
	int numSize;

	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

	int findScore(vector<int>& nums, vector<int>& multipliers, int left, int index) {
		if (mulSize == index) {
			return 0;
		}

		if (-9 != dpScore[index][left]) {
			return dpScore[index][left];
		}

		int right = numSize - 1 - (index - left);

		return dpScore[index][left] = maxValue (
			multipliers[index] * nums[left] + findScore(nums, multipliers, left + 1, index + 1),
			multipliers[index] * nums[right] + findScore(nums, multipliers, left, index + 1)
		);
	}

public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		mulSize = multipliers.size();
		numSize = nums.size();
		for (int i = 0; i <= mulSize; i++) {
			for (int j = 0; j <= mulSize; j++) {
				dpScore[i][j] = -9;
			}
		}

		return findScore(nums, multipliers, 0, 0);
	}
};