class Solution {
    char shift(char ch, char digitCh) {
        int digit = digitCh - 48;
        
        return ch + digit;
    }
    
public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                s[i] = shift(s[i - 1], s[i]);
            }
        }
        
        return s;
    }
};