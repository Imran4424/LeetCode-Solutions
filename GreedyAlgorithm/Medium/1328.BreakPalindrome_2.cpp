
class Solution {
public:
    string breakPalindrome(string palindrome) {
        // not possible scenarios
        if (palindrome.size() < 2) {
            return "";
        }
        
        if (palindrome[0] != 'a') {
            palindrome[0] = 'a';
            return palindrome;
        }
        
        int halfSize = palindrome.size() / 2;
        
        for (int i = 1; i < halfSize; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[palindrome.size() - 1] = 'b';
        
        return palindrome;
    }
};