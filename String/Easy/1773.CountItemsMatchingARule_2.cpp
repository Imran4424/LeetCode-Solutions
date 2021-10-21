class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        
        for (int i = 0; i < items.size(); i++) {
            if ("type" == ruleKey) {
                if (ruleValue == items[i][0]) {
                    count++;
                }
            } else if ("color" == ruleKey) {
                if (ruleValue == items[i][1]) {
                    count++;
                }
            } else {
                if (ruleValue == items[i][2]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};