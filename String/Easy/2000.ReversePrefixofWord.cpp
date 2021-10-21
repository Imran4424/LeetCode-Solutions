class Solution {
    string reverse(string str) {
        string revString = "";
        
        for (int i = str.size() - 1; i >= 0; i--) {
            revString += str[i];
        }
        
        return revString;
    }
    
public:
    string reversePrefix(string word, char ch) {
        bool targetFound = false;
        string revPre = "";
        
        for (char current: word) {
            if (targetFound) {
                revPre += current;
            } else {
                if (current == ch) {
                    revPre += current;
                    revPre = reverse(revPre);
                    targetFound = true;
                } else {
                    revPre += current;
                }
            }
        }
        
        return revPre;
    }
};