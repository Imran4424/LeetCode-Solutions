class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        int k;
        
        if ("type" == ruleKey) {
            k = 0;
        } else if ("color" == ruleKey) {
            k = 1;
        } else {
            k = 2;
        }
        
        for (int i = 0; i < items.size(); i++) {
            if(ruleValue == items[i][k]) {
                count++;
            }
        }
        
        return count;
    }
};