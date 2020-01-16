
/*

*/

bool isUnique(char *firstStr, char *secondStr) {
    int i;
    
    for(i = 0; firstStr[i] != '\0' && secondStr[i] != '\0'; i++) {
        if(firstStr[i] != secondStr[i]) {
            return true;
        }
    }
    
    if(firstStr[i] != secondStr[i]) {
        return true;
    }
    
    return false;
}

void initUnique(bool *unique, int emailsSize) {
    for(int i = 0; i < emailsSize; i++) {
        unique[i] = true;
    }
}

int numUniqueEmails(char ** emails, int emailsSize) {
    
    for(int i = 0; i < emailsSize; i++) {
        printf("%s\n", emails[i]);
        char filterMail[100];
        int x = 0;
        bool isLocal = true;
        for(int j = 0; j < emails[i][j] != '@'; j++) {
            if('.' == emails[i][j]) {
               continue; 
            }
            
            if('+' == emails[i][j]) {

                while('@' != emails[i][j]) {
                    j++;
                }
            }
            
            if('@' == emails[i][j]) {
                for(int k = j; emails[i][k] != '\0'; k++) {
                    filterMail[x++] = emails[i][k];
                }
                
                break;
            }
            
            filterMail[x++] = emails[i][j];
        }
        
        for(int j = 0; j < x; j++) {
            emails[i][j] = filterMail[j];
        }
        
        emails[i][x] = '\0';
        printf("%s\n\n", emails[i]);    
    }
    
    bool unique[emailsSize];
    initUnique(unique, emailsSize);
    
    int numUnique = emailsSize;
    
    for(int i = 0; i < emailsSize; i++) {
        for(int j = i + 1; j < emailsSize; j++) {
            
            if(unique[j]) {
                
                if(!isUnique(emails[i], emails[j])) {
                    numUnique--;
                    unique[j] = false;
                }
            }
        } 
    }
    
    
    return numUnique;
}
