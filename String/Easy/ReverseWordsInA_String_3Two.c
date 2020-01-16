


char * reverseWords(char * s){
    int lastStart = 0;
    int hIndex = lastStart;
    char helperStr[100];
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(' ' == s[i]) {
            continue;
        }
        
        helperStr[hIndex++] = s[i];
        
        if(' ' == s[i + 1] || '\0' == s[i + 1]) {
            int k, x;
            for(k = lastStart, x = hIndex - 1; k <= i && x >= 0 ; k++, x--) {
                s[k] = helperStr[x];
            }
            
            hIndex = 0;
            lastStart = i + 2;
        }
    }
    
    return s;
}