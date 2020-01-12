int balancedStringSplit(char * s){
    int pairCount = 0, rCount = 0, lCount = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        // we are checking at the begin of the loop
        // for that reason we are unable to count the last occurence
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

    // returning with + 1 cause in loop we skip last count
    return pairCount + 1;
}
