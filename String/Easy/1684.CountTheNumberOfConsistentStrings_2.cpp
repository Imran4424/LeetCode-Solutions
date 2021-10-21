class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        if (26 == allowed.size()) {
            return words.size();
        }
        
        int count = words.size();
        bool status[26] = {0};
        
        for (char c: allowed) {
            status[c - 'a'] = true;
        }
        
        for (string word: words) {
            for (char c: word) {
                if(!status[c - 'a']) {
                    count--;
                    break;
                }
            }
        }
        
        return count;
    }
};