


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
        //printf("%s\n\n", emails[i]);
        
        for(int j = 0; j < emails[i][j] != '@'; j++) {
            
            if('.' == emails[i][j]) {
                // printf("there's a .\n");
                /// the condition is really clever :)
                for(int x = j; emails[i][x - 1 + 1] != '\0'; x++) {
                    emails[i][x] = emails[i][x + 1];
                }
                
            }
            
            if('+' == emails[i][j]) {
                // printf("there's a +\n");
                int target = j + 1;
                
                while('@' != emails[i][target]) {
                    target++;
                }
                
                int needAdd = target - j;
                
                for(int x = j; emails[i][x - 1 + needAdd] != '\0'; x++) {
                    emails[i][x] = emails[i][x + needAdd];
                }
            }
            
            if('@' == emails[i][j]) {
                break;
            }
        }
        
        //printf("%s\n\n", emails[i]);    
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