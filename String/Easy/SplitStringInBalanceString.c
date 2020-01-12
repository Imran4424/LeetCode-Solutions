int balancedStringSplit(char * s){
    int pairCount = 0, rCount = 0, lCount = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(0 != rCount && 0 != lCount && rCount == lCount) {
            pairCount++;
            rCount = lCount = 0;
        }
        
        if('R' == s[i]) {
            rCount++;
        } else if('L' == s[i]) {
            lCount++;
        }        
    }

    return pairCount+1;
}
