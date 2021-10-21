class Solution {
public:
    int balancedStringSplit(string s) {
        int spikeStatus = 0;
        int count = 0;
        
        if('R' == s[0]) {
            spikeStatus++;
        } else {
            spikeStatus--;
        }
        
        for (int i = 1; i < s.size(); i++) {
            if('R' == s[i]) {
                spikeStatus++;
            } else {
                spikeStatus--;
            }
            
            if (0 == spikeStatus) {
                count++;
            }
        }
        
        return count;
    }
};