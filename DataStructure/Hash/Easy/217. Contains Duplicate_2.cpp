

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		set<int> uniqueList;

		for (int i = 0; i < nums.size(); i++) {
			if(uniqueList.count(nums[i])) {
				return true;
			}

			uniqueList.insert(nums[i]);
		}

		return false;
    }
};