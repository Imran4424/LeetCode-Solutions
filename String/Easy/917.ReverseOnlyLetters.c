
/*
    https://leetcode.com/problems/reverse-only-letters/
*/

char * reverseOnlyLetters(char * s) {
    char tempStr[101];
    int index = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') || s[i] >= 'a' && s[i] <= 'z') {
            tempStr[index++] = s[i];
        }
    }
    
    index--;
    for(int i = 0; s[i] != '\0'; i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') || s[i] >= 'a' && s[i] <= 'z') {
            s[i] = tempStr[index--];
        }
    }
    
    return s;
}