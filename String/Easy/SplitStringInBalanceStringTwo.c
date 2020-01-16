
/*
    
*/

int balancedStringSplit(char * s){
    int pairCount = 0, rCount = 0, lCount = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if('R' == s[i]) {
            rCount++;
        } else if('L' == s[i]) {
            lCount++;
        }
        
        if(0 != rCount && 0 != lCount && rCount == lCount) {
            pairCount++;
            rCount = lCount = 0;
        }
    }

    return pairCount;
}