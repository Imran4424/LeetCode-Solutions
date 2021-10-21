class Solution {
public:
    string removeOuterParentheses(string s) {
        string newStr = "";
        int outerCount = 0;
        
        for (char ch: s) {
            if ('(' == ch) {
                if (outerCount++) {
                    newStr += ch;
                }
            } else {
                if (--outerCount) {
                    newStr+= ch;
                }
            }
        }
        
        return newStr;
    }
};