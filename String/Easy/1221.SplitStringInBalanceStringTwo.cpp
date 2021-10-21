class Solution {
public:
    int balancedStringSplit(string s) {
        int spikeStatus = 0;
        int count = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if('R' == s[i]) {
                spikeStatus++;
            } else {
                spikeStatus--;
            }
            
            if (0 != i && 0 == spikeStatus) {
                count++;
            }
        }
        
        return count;
    }
};