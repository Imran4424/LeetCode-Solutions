
class Solution {
    int maxValue(int x, int y) {
        if (x > y) {
            return x;
        }
        
        return y;
    }

    int dpRob(vector<int>& nums, int index, int size) {
        int robOne = nums[index];
        int robTwo = maxValue(nums[index], nums[index + 1]);
        
        for (int i = index + 2; i < size; i++) {
            int currentRob = maxValue(robTwo, robOne + nums[i]);
            robOne = robTwo;
            robTwo = currentRob;
        }
        
        return robTwo;
    }
    
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums[0];
        }
        
        if (nums.size() < 3) {
            return maxValue(nums[0], nums[1]);
        }
        
        return maxValue(dpRob(nums, 0, nums.size() - 1), dpRob(nums, 1, nums.size()));
    }
};