
char * removeDuplicates(char * s, int target){
    char stack[100005];
    int frequency[100005];
    int top = 0;

    for(int i = 0; s[i]; i++) {
        if(top > 0 && stack[top - 1] == s[i]) {
            frequency[top - 1]++;

            if(frequency[top - 1] == target) {
                top--;
            }
            
        } else {
            stack[top] = s[i];
            frequency[top] = 1;
            top++;
        }
    }

    int i, j;

    for(i = j = 0; i < top; i++) {
        while(frequency[i] > 0) {
            s[j++] = stack[i];
            frequency[i]--;
        }
    }

    s[j] = '\0';

    return s;
}