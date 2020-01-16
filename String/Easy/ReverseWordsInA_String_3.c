
/*
    https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

char * reverseWords(char * s){
    int lastStart = 0;
    int length = 0;
    
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(' ' == s[i]) {
            continue;
        }
        
        length++;
        
        if(' ' == s[i + 1] || '\0' == s[i + 1]) {
            int endPoint = lastStart + (length / 2);
            int lastIndex = lastStart + length - 1;
            
            for(int k = lastStart; k < endPoint ; k++) {
                char temp = s[k];
                
                s[k] = s[lastIndex - k + lastStart];
                s[lastIndex - k + lastStart] = temp;
            }
            
            lastStart = i + 2;
            length = 0;
        }
    }
    
    return s;
}