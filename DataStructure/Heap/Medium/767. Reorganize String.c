/// Ashraf vai code
/// reformated by me


char * reorganizeString(char * S){
    int freq[26]={0};

    int i, last, max, maxIndex, len, index;

    for (i=0; S[i]; i++){
        freq[S[i]-'a']++;
    }
    len = i;

    char *result = (char *) malloc(sizeof(char)*(len+1));

    last = -1;

    for (index=0; index < len; index++) {
        max = 0;

        /// calculating max
        for (i = 0; i < 26; i++) {
            if (freq[i] > max && i != last) {
                max = freq[i];
                maxIndex = i;
            }
        }

        /// if not possible
        if (max * 2 > len+1){
            return "";
        }

        result[index] = maxIndex + 'a';
        freq[maxIndex]--;
        last = maxIndex;
    }
    result[index]='\0';

    return result;
}

