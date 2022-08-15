

class Solution {
	int maxValue(int x, int y) {
		if (x > y) {
			return x;
		}

		return y;
	}

public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		int mulSize = multipliers.size();
		int numSize = nums.size();
		
		int dpScore[mulSize + 1][mulSize + 1];
		memset(dpScore, 0, (mulSize + 1) * (mulSize + 1) * sizeof(int));

		for (int i = 0; i < mulSize; i++) {
			for (int left = 0; left < i; left++) {
				int right = numSize - 1 - (i - left);

				dpScore[i][left] = maxValue(
					multipliers[i] * nums[left] + dpScore[i + 1][left + 1],
					multipliers[i] * nums[right] + dpScore[i + 1][left]
				);
			}
		}


		return dpScore[mulSize][mulSize];
	}
};

/*
	showing error
*/