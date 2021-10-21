class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        if (26 == allowed.size()) {
            return words.size();
        }
        
        int count = words.size();
        size_t found;
        string notAllowed = "";
        
        for (char i = 'a'; i <= 'z'; i++) {
            found = allowed.find(i);
            if (found == string::npos) {
                notAllowed += i;
            }
        }
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < notAllowed.size(); j++) {
                found = words[i].find(notAllowed[j]);
                
                if (found != string::npos) {
                    count--;
                    break;
                }
            }
        }
        
        return count;
    }
};