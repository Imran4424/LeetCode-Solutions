class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        if (26 == allowed.size()) {
            return words.size();
        }
        
        int count = words.size();
        set<char> allowedSet;
        
        for (char c: allowed) {
            allowedSet.insert(c);
        }
        
        for (string word: words) {
            for (char c: word) {
                if (0 == allowedSet.count(c)) {
                    count--;
                    break;
                }
            }
        }
        
        return count;
    }
};