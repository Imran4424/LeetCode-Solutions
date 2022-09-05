
class Solution {
    int dp[101];
    bool firstSelected;
    
    int maxValue(int x, int y) {
        if (x > y) {
            return x;
        }
        
        return y;
    }

    int dpRob(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        
        if (index == nums.size() - 1 && firstSelected) {
            return 0;
        }
        
        if (-1 != dp[index]) {
            return dp[index];
        }
        
        return dp[index] = maxValue(dpRob(nums, index + 1), dpRob(nums, index + 2) + nums[index]);
    }
    
public:
    int rob(vector<int>& nums) {
        if (1 == nums.size()) {
            return nums[0];
        }
        
        for (int i = 0; i <= nums.size(); ++i) {
            dp[i] = -1;
        }
        
        firstSelected = false;
        int right = dpRob(nums, 1);
        
        for (int i = 0; i <= nums.size(); ++i) {
            dp[i] = -1;
        }
        
        firstSelected = true;
        int left = dpRob(nums, 0);
        
        return maxValue(left, right);
    }
};