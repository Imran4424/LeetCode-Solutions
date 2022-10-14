

class Solution {
    vector <string> sentences;
    bool dp[21];
    
    bool dpWordBreak(string text, int index, vector<string>& wordDict, string current) {
        if (index >= text.size()) {
            current.pop_back();
            sentences.push_back(current);
            return dp[index] = 1;
        }
        
        if (0 == dp[index]) {
            return dp[index];
        }
        
        
        bool mainStatus = false;
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
                status = dpWordBreak(text, index + i, wordDict, current + word + " ");
                
                if (status) {
                    mainStatus = status;
                }
            }
        }
        
        return dp[index] = mainStatus;
    }
    
public:
    vector<string> wordBreak(string text, vector<string>& wordDict) {
        int i;
        for (i = 0; text[i]; ++i) {
            dp[i] = true;
        }
        dp[i] = true;
        
        dpWordBreak(text, 0, wordDict, "");
        return sentences;
    }
};