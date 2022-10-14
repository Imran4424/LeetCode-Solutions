

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        
        int mySize = nums.size() - 1;
        int size = nums.size();
        
        // generate max and min
        int maxList[nums.size()], minList[nums.size()];
        maxList[mySize] = nums[mySize];
        minList[0] = nums[0];
        for (int i = 1, j = mySize - 1; i < size; ++i, --j) {
            if (nums[j] > maxList[j + 1]) {
                maxList[j] = nums[j];
            } else {
                maxList[j] = maxList[j + 1];
            }
            
            if (nums[i] < minList[i - 1]) {
                minList[i] = nums[i];
            } else {
                minList[i] = minList[i - 1];
            }
        }
        
        for (int middle = 1; middle < mySize; ++middle) {
            // nums[i] is the first one
            // now find second one
            if (minList[middle - 1] < nums[middle] && nums[middle] < maxList[middle + 1]) {
                return true;
            }
        }
        
        return false;
    }
};