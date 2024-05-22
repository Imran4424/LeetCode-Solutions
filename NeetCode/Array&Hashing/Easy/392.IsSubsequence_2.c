
bool isSubsequence(char * targetStr, char * searchStr){
    
    int k;
    for(int i = k = 0; searchStr[i] && targetStr[k]; i++) {
        if(searchStr[i] == targetStr[k]) {
            k++;
        }
    }

    if(targetStr[k]) {
        return false;
    }

    return true;
}