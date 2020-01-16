
/*
    https://leetcode.com/problems/reverse-string-ii/
*/


char * reverseStr(char * s, int k) {
    int count = 1;
    int lastStart = (count - 1) * k;
    
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(i == lastStart) {
            char tempStr[10001];
            int index = 0;
            // copying
            for(int x = i; x < count * k && s[x] != '\0'; x++) {
                tempStr[index++] = s[x];
                 //printf("inside copy\n");
            }

           
            
            // reversing
            int m, n;
            for(m = index - 1, n = i; m >= 0 && n < count * k && s[n] != '\0'; m--, n++){
                s[n] = tempStr[m];
                //printf("inside reverse\n");
            }

            count = count + 2;
            lastStart = (count - 1) * k;
        }        
    }
    
    return s;
}