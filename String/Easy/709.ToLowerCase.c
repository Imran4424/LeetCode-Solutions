
/*
	https://leetcode.com/problems/to-lower-case/
*/

char * toLowerCase(char * str){
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    
    return str;
}
