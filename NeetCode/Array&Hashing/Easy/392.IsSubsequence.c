
bool isSubsequence(char * targetStr, char * searchStr){
    int tSize = strlen(targetStr);
    int trueCount = 0;
    
    for(int i = 0; searchStr[i] && trueCount < tSize; i++) {
        for(int j = trueCount; targetStr[j]; j++) {
            if(searchStr[i] == targetStr[j]) {
                trueCount++;
                break;
            }
        }
    }

    if(trueCount == tSize) {
        return true;
    }

    return false;
}