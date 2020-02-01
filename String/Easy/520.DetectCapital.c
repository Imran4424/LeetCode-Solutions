

bool detectCapitalUse(char * word) {
    bool firstCapital = false;
    int capitalCount = 0, smallCount = 0, length = 0;

    for(int i = 0; word[i] != '\0'; i++) {
        if(0 == i && word[i] >= 'A' && word[i] <= 'Z') {
            firstCapital = true;
        }
            
        if(word[i] >= 'A' && word[i] <= 'Z') {
            capitalCount++;
        } else {
            smallCount++;
        }
            
        length++;
    }
    
    if(length == capitalCount || length == smallCount) {
        return true;
    }
    
    if(firstCapital && 1 == capitalCount) {
        return true;
    }
    
    return false;
}

