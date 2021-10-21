class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        
        if ("type" == ruleKey) {
            for (int i = 0; i < items.size(); i++) {
                if (ruleValue == items[i][0]) {
                    count++;
                }
            }
        } else if ("color" == ruleKey) {
            for (int i = 0; i < items.size(); i++) {
                if (ruleValue == items[i][1]) {
                    count++;
                }
            }
        } else {
            for (int i = 0; i < items.size(); i++) {
                if (ruleValue == items[i][2]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};