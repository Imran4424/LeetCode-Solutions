

class Solution {
	int absolute(int x) {
		if (x < 0) {
			return -x;
		}

		return x;
	}

public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());

		int minDiff = INT_MAX;
		int numSize = nums.size();

		for (int i = 0; i < numSize && 0 != minDiff; ++i) {
			int low = i + 1;
			int high = numSize - 1;

			while (low < high && 0 != minDiff) {
				int sum = nums[i] + nums[low] + nums[high];

				if (absolute(target - sum) < absolute(minDiff)) {
					minDiff = target - sum;
				}

				if (sum < target) {
					++low;
				} else {
					--high;
				}
			}
		}

		return target - minDiff;
	}
};