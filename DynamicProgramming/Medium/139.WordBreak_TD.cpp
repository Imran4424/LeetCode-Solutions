

class Solution {
    int dp[301];
    
    bool dpWordBreak(string text, vector<string>& wordDict, int index) {
        if (index >= text.size()) {
            return dp[index] = 1;
        }
        
        if (-1 != dp[index]) {
            return dp[index];
        }
        
        for (string& word : wordDict) {
            bool status = true;
            int i;
            for (i = 0; word[i]; ++i) {
                if (word[i] != text[index + i]) {
                    status = false;
                    break;
                }
            }
            
            if (status) {
                status = dpWordBreak(text, wordDict, index + i);
                
                if (status) {
                    return dp[index] = status;
                }
            }
        }
        
        return dp[index] = 0;
    }
    
public:
    bool wordBreak(string text, vector<string>& wordDict) {
        int i;
        for (i = 0; text[i]; ++i) {
            dp[i] = -1;
        }
        dp[i] = -1;
        
        return dpWordBreak(text, wordDict, 0);
    }
};