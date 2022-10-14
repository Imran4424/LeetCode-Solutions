
class Solution {
    bool isPalindrome(string text) {
        int left = 0;
        int right = text.size() - 1;
        
        while(left <= right && text[left] == text[right]) {
            left++;
            right--;
        }
        
        if (left > right) {
            return true;
        }
        
        return false;
    }
    
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
        
        for (int i = 1; palindrome[i]; ++i) {
            if (palindrome[i] != 'a') {
                char temp = palindrome[i];
                palindrome[i] = 'a';
                
                if (!isPalindrome(palindrome)) {
                    return palindrome;
                }
                
                palindrome[i] = temp;
            }
        }
        
        palindrome[palindrome.size() - 1] = 'b';
        
        return palindrome;
    }
};