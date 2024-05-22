
void init(int *sCount, int *tCount) {
    for(int i = 0; i < 26; i++) {
        sCount[i] = 0;
        tCount[i] = 0;
    }
}

void findCharCount(char *str, int *cCount) {
    for(int i = 0; str[i]; i++) {
        cCount[str[i] - 'a']++;
    }
}

bool isAnagram(char * s, char * t){
    int sCount[26];
    int tCount[26];

    init(sCount, tCount);

    findCharCount(s, sCount);
    findCharCount(t, tCount);

    for(int i = 0; i < 26; i++) {
            if(sCount[i] != tCount[i]) {
                return false;
            }
    }

    return true;
}

