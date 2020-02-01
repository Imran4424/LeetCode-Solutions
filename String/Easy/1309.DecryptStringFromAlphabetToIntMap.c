
/*
    https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
*/

char * freqAlphabets(char * s){
    char digitStr[25];
    int k = 0, tCount = 0;
    
    char *translation = malloc(sizeof(char) * 1001);
    
    for(int i = 0; s[i] != '\0'; i++) {
        if('#' == s[i]){
            //reverse string
            char reverse[15], reIndex = 0;
            //last two digit pop
            int chNum = 0, powerCount = 1;
                
            for(int m = k - 1; m >= k-2; m--) {
                chNum = (digitStr[m] - 48) * powerCount + chNum;
                powerCount = powerCount * 10;
            }
            
            reverse[reIndex++] = 'a' + chNum - 1;
            
            // rest of the digits
            for(int m = k - 3; m >= 0; m--) {
                reverse[reIndex++] = 'a' + digitStr[m] - 48 - 1;
            }
            
            if(k > 2) {
                for(int m = reIndex - 1; m >= 0; m--) {
                    translation[tCount++] = reverse[m]; 
                }            
            } else {
                translation[tCount++] = reverse[0];
            }
            
            k = 0;
            continue;
        }
        
        digitStr[k] = s[i];
        k++;
    }
    
    for(int m = 0; m < k; m++) {
        translation[tCount++] = 'a' + digitStr[m] - 48 - 1;
    }
    
    translation[tCount] = '\0';
    return translation;
}