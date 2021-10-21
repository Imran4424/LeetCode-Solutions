class Solution {
    bool isVowel(char ch) {
        if('a' == ch || 'e' == ch || 'i' == ch || 'o' == ch || 'u' == ch || 'A' == ch || 'E' == ch || 'I' == ch || 'O' == ch || 'U' == ch) {
            return true;
        }
        
        return false;
    }
    
public:
    bool halvesAreAlike(string s) {
        int length = s.size();
        int half = length / 2;
        int firstVowel = 0;
        int secondVowel = 0;
        
        for (int i = 0; i < length; i++) {
            if (isVowel(s[i])) {
                if (i < half) {
                    firstVowel++;
                } else {
                    secondVowel++;
                }
            }
            
        }
        
        return firstVowel == secondVowel;
    }
};