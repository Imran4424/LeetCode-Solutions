class Solution {
public:
    string truncateSentence(string s, int k) {
        string truncateStr = "";
        int spaceCount = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if(' ' == s[i]) {
                spaceCount++;
            }
            
            if (spaceCount == k) {
                break;
            }
            
            truncateStr += s[i];
        }
        
        return truncateStr;
    }
};