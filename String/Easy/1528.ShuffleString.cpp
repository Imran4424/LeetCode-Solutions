
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string restoredStr = s;
        
        for (int i = 0; i < s.size(); i++) {
            restoredStr[indices[i]] = s[i];
        }
        
        return restoredStr;
    }
};