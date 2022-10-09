


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

		if (nums.size() == 1) {
			return nums[0];
		}

		int minVal = nums[0];
		int maxVal = nums[0];
        
        	int maxP = nums[0];
		
		for (int i = 1; i < nums.size(); ++i) {
			vector <int> current;
			current.push_back(nums[i]);
			current.push_back(minVal * nums[i]);
			current.push_back(maxVal * nums[i]);

			minVal = current[0];
			maxVal = current[0];

			for (int i = 1; i < 3; ++i) {
				if (current[i] < minVal) {
					minVal = current[i];
				}

				if (current[i] > maxVal) {
					maxVal = current[i];
				}
			}
   
			if (maxVal > maxP) {
				maxP = maxVal;
			}
		}

		return maxP;
	}
};

