
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

		int closest = nums[0] + nums[1] + nums[2];
		int greaterClosest = closest;

		if (closest == target) {
			return target;
		}

		int breakPos = -1;

		// now sliding window
		for (int i = 3; i < nums.size(); ++i) {
			int current = closest + nums[i] - nums[i - 3];

			if (current == target) {
				return target;
			} else if (current > target) {
				greaterClosest = current;
				breakPos = i;
				break;
			} else {
				closest = current;
			}
		}

		if (absolute(target - closest) > absolute(target - greaterClosest)) {
			closest = greaterClosest;
		}

		if (-1 != breakPos) {
			int window = 10;
			// start
			int startP;
			if (breakPos - window >= 0) {
				startP = breakPos - window;
			} else {
				startP = 0;
			}

			// end
			int endP;
			if (breakPos + window < nums.size()) {
				endP = breakPos + window;
			} else {
				endP = nums.size() - 1;
			}

			// now nested 3 loop
			for (int i = startP; i <= endP; ++i) {
				for (int j = startP; j <= endP; ++j) {
					if (i == j) {
						continue;
					}

					for (int k = startP; k <= endP; ++k) {
						if (i == k || j == k) {
							continue;
						}

						int current = nums[i] + nums[j] + nums[k];

						if (current == target) {
							return target;
						}

						if (absolute(target - current) < absolute(target - closest)) {
							closest = current;
						}
					}
				}
			}
		}

		return closest;
	}
};