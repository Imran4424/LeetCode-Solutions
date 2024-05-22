class Solution {
    void findCharCount(string s, int *cCount) {
        for (int i = 0; s[i]; ++i) {
            int index = s[i] - 'a';
            cCount[index]++;
        }
    }
    
public:
    bool isAnagram(string s, string t) {        
        if (s.size() != t.size()) {
            return false;
        }
        
        int sCount[26] = {0};
        int tCount[26] = {0};
        
        findCharCount(s, sCount);
        findCharCount(t, tCount);
        
        for(int i = 0; i < 26; i++) {
                if(sCount[i] != tCount[i]) {
                    return false;
                }
        }

        return true;
        
    }
};