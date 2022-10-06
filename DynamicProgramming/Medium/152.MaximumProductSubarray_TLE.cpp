
class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int maxP = INT_MIN;

		for (int i = 0; i < nums.size(); ++i) {
			int currentP = 1;

			for (int j = i; j < nums.size(); ++j) {
				currentP *= nums[j];

				if (currentP > maxP) {
					maxP = currentP;
				}
			}
		}

		return maxP;
	}
};

/*
	This code will end up in TLE
	Complexity O(n^2)

	all substring logic

*/